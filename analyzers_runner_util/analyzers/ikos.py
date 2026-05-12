import subprocess
import time
import os
import shutil
from analyzers.abstract_analyzer import AbstractAnalyzer

class IkosAnalyzer(AbstractAnalyzer):
    def __init__(self, extra_args=None):
        self.extra_args = extra_args or []
        self.main_func = ["--entry-point=func", "-I/home/shika/diplom/analyzer_runner_util/include"]
        self.extra_good = ["-I/home/shika/diplom/tests/C/testcasesupport", "-DOMITBAD"]
        self.extra_bad = ["-I/home/shika/diplom/tests/C/testcasesupport", "-DOMITGOOD"]

    def get_name(self):
        return "ikos"

    def __get_file_name(self, file_path, suffix):
        base_name = os.path.splitext(os.path.basename(file_path))[0]
        return f"{base_name}_{suffix}"
    
    def __run_cmd(self, cmd, file_path):
        file_name = os.path.splitext(os.path.basename(file_path))[0]
        temp_dir = f"ikos_tmp_{file_name}"
        temp_file = f"{temp_dir}/test.db"

        if os.path.exists(temp_dir):
            shutil.rmtree(temp_dir)
        os.makedirs(temp_dir)
        
        cmd_with_dop_option = cmd + ["--output-db", temp_file]

        try:
            start = time.time()
            
            try:
                proc = subprocess.run(
                    cmd_with_dop_option,
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                    timeout=10
                )
            except subprocess.TimeoutExpired:
                return {
                    "raw_output": "TIMEOUT",
                    "runtime_sec": time.time() - start
                }
            
            runtime = time.time() - start
            
            return {
                "raw_output": proc.stdout.strip() + proc.stderr.strip(),
                "runtime_sec": runtime
            }
        finally:
            if os.path.exists(temp_dir):
                shutil.rmtree(temp_dir)

    def run(self, file_path):
        cmd = ["ikos"] + self.extra_args + self.main_func + [file_path]
        
        return self.__run_cmd(cmd, file_path)
    
    def run_good(self, file_path):
        cmd = ["ikos"] + self.extra_args + self.extra_good + ["--entry-point", self.__get_file_name(file_path, "good")] + [file_path]
        
        return self.__run_cmd(cmd, file_path)
    
    def run_bad(self, file_path):
        cmd = ["ikos"] + self.extra_args + self.extra_bad + ["--entry-point", self.__get_file_name(file_path, "bad")] + [file_path]
        
        return self.__run_cmd(cmd, file_path)
