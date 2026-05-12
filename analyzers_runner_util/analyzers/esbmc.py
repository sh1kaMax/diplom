import subprocess
import time
import os
from analyzers.abstract_analyzer import AbstractAnalyzer

class ESBMCAnalyzer(AbstractAnalyzer):
    def __init__(self, extra_args=None):
        self.extra_args = extra_args or [
            "--unwind", "100", "--overflow-check", "--printf-check",
            "--nan-check", "--memory-leak-check", "--unsigned-overflow-check",
            "--ub-shift-check", "--struct-fields-check", "--unknown-method-args-check"
        ]
        self.if_error_with_include = ["--no-library"]
        self.main_func = ["--function", "func"]
        self.extra_good = ["-I/home/shika/diplom/tests/C/testcasesupport", "-I/home/shika/diplom/analyzers_runner_util/include", "-DOMITBAD"] # -DINCLUDEMAIN
        self.extra_bad = ["-I/home/shika/diplom/tests/C/testcasesupport",  "-I/home/shika/diplom/analyzers_runner_util/include", "-DOMITGOOD"] # -DINCLUDEMAIN

    def get_name(self):
        return "esbmc"

    def __get_file_name(self, file_path, suffix):
        base_name = os.path.splitext(os.path.basename(file_path))[0]
        return f"{base_name}_{suffix}"
    
    def __run_cmd(self, cmd, repeat = False):
        start = time.time()
        
        try:
            proc = subprocess.run(
                cmd,
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

        if ((not repeat) and ("typedef redefinition with different types" in proc.stdout.strip() or "typedef redefinition with different types" in proc.stderr.strip())):
            return self.__run_cmd(cmd + self.if_error_with_include, True)
        
        return {
            "raw_output": proc.stdout.strip() + proc.stderr.strip(),
            "runtime_sec": runtime
        }

    def run(self, file_path):
        cmd = ["esbmc"] + self.extra_args + self.main_func + [file_path]
        
        return self.__run_cmd(cmd)
    
    def run_good(self, file_path):
        cmd = ["esbmc"] + self.extra_args + self.extra_good + ["--function", self.__get_file_name(file_path, "good")] + [file_path]
        
        return self.__run_cmd(cmd)
    
    def run_bad(self, file_path):
        cmd = ["esbmc"] + self.extra_args + self.extra_bad + ["--function", self.__get_file_name(file_path, "bad")] + [file_path]
        
        return self.__run_cmd(cmd)
