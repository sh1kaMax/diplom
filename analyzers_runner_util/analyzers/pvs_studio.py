import subprocess
import time
import os
import tempfile
import shutil
from analyzers.abstract_analyzer import AbstractAnalyzer

class PVSStudio(AbstractAnalyzer):
    def __init__(self, extra_args=None):
        self.include_path = ["-I/home/shika/diplom/tests/C/testcasesupport", "-I/home/shika/diplom/analyzers_runner_util/include"]
        self.extra_good = ["-DINCLUDEMAIN", "-DOMITBAD"]
        self.extra_bad = ["-DINCLUDEMAIN", "-DOMITGOOD"]

    def get_name(self):
        return "pvs-studio"

    def __run_cmd(self, cmd, timeout=30):
        start = time.time()
        
        try:
            proc = subprocess.run(
                cmd,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                timeout=timeout,
                shell=False
            )
        except subprocess.TimeoutExpired:
            return {
                "raw_output": "TIMEOUT",
                "runtime_sec": time.time() - start
            }
        
        runtime = time.time() - start
        
        return {
            "raw_output": proc.stdout.strip() + "\n" + proc.stderr.strip(),
            "runtime_sec": runtime
        }

    def __run_pvs_analysis(self, file_path, extra_defines):
        file_name = os.path.splitext(os.path.basename(file_path))[0]
        temp_dir = f"pvs_studio_tmp_{file_name}"

        if os.path.exists(temp_dir):
            shutil.rmtree(temp_dir)
        os.makedirs(temp_dir)
        
        try:
            trace_path = f"{temp_dir}/strace_out"
            object_file_path = f"{temp_dir}/object.o"
            trace_cmd = [
                "pvs-studio-analyzer", "trace", "-o", trace_path, "--",
                "gcc", "-c", file_path,
                "-o", object_file_path
            ] + self.include_path + extra_defines
            
            trace_result = self.__run_cmd(trace_cmd, timeout=30)
            if "error" in trace_result["raw_output"].lower() or "failed" in trace_result["raw_output"].lower():
                return {
                    "raw_output": f"Trace failed: {trace_result['raw_output']}",
                    "runtime_sec": trace_result["runtime_sec"]
                }
            
            log_path = f"{temp_dir}/test.log"
            analyze_cmd = [
                "pvs-studio-analyzer", "analyze", "-f", trace_path,
                "-o", log_path
            ]
            analyze_result = self.__run_cmd(analyze_cmd, timeout=60)
            
            tasks_path = f"{temp_dir}/test.tasks"
            convert_cmd = [
                "plog-converter",
                "-a", "GA:1,2,3",
                "-t", "tasklist",
                "-o", tasks_path,
                log_path
            ]
            convert_result = self.__run_cmd(convert_cmd, timeout=30)
            
            output = []
            if os.path.exists(tasks_path):
                with open(tasks_path, 'r') as f:
                    output.append(f.read())
            
            if convert_result["raw_output"].strip():
                output.append(f"CONVERTER OUTPUT: {convert_result['raw_output']}")
            
            total_runtime = trace_result["runtime_sec"] + analyze_result["runtime_sec"] + convert_result["runtime_sec"]
            
            return {
                "raw_output": "\n".join(output) if output else "No issues found",
                "runtime_sec": total_runtime
            }
        finally:
            if os.path.exists(temp_dir):
                shutil.rmtree(temp_dir)

    def run_good(self, file_path):
        return self.__run_pvs_analysis(file_path, self.extra_good)

    def run_bad(self, file_path):
        return self.__run_pvs_analysis(file_path, self.extra_bad)

    def run(self, file_path):
        return self.__run_pvs_analysis(file_path, [])