import subprocess
import time
import os
import tempfile
import shutil

class PVSStudio:
    def __init__(self, extra_args=None):
        self.include_path = "/home/shika/diplom/tests/C/testcasesupport"
        self.extra_good = ["-DINCLUDEMAIN", "-DOMITBAD"]
        self.extra_bad = ["-DINCLUDEMAIN", "-DOMITGOOD"]
        
        self.temp_dir = tempfile.mkdtemp(prefix="pvs_temp_")

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

    def __cleanup(self):
        if os.path.exists(self.temp_dir):
            shutil.rmtree(self.temp_dir, ignore_errors=True)

    def __run_pvs_analysis(self, file_path, extra_defines):
        trace_cmd = [
            "pvs-studio-analyzer", "trace", "--",
            "gcc", "-c", file_path,
            f"-I{self.include_path}"
        ] + extra_defines
        
        trace_result = self.__run_cmd(trace_cmd, timeout=30)
        if "error" in trace_result["raw_output"].lower() or "failed" in trace_result["raw_output"].lower():
            self.__cleanup()
            return {
                "raw_output": f"Trace failed: {trace_result['raw_output']}",
                "runtime_sec": trace_result["runtime_sec"]
            }
        
        analyze_cmd = [
            "pvs-studio-analyzer", "analyze",
            "-o", "test.log"
        ]
        analyze_result = self.__run_cmd(analyze_cmd, timeout=60)
        
        convert_cmd = [
            "plog-converter",
            "-a", "GA:1,2,3",
            "-t", "tasklist",
            "-o", "test.tasks",
            "test.log"
        ]
        convert_result = self.__run_cmd(convert_cmd, timeout=30)
        
        output = []
        if os.path.exists("test.tasks"):
            with open("test.tasks", 'r') as f:
                output.append(f.read())
        
        if convert_result["raw_output"].strip():
            output.append(f"CONVERTER OUTPUT: {convert_result['raw_output']}")
        
        total_runtime = trace_result["runtime_sec"] + analyze_result["runtime_sec"] + convert_result["runtime_sec"]
        self.__cleanup()
        
        return {
            "raw_output": "\n".join(output) if output else "No issues found",
            "runtime_sec": total_runtime
        }

    def run_good(self, file_path):
        return self.__run_pvs_analysis(file_path, self.extra_good)

    def run_bad(self, file_path):
        return self.__run_pvs_analysis(file_path, self.extra_bad)

    def run(self, file_path):
        return self.__run_pvs_analysis(file_path, [])