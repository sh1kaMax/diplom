import subprocess
import time
import os

class FramaCAnalyzer:
    def __init__(self, extra_args=None):
        self.extra_args = extra_args or ["-eva", "-warn-signed-overflow", "-warn-unsigned-overflow"]
        self.main_func = ["-main", "func"]
        self.extra_good = ["-cpp-extra-args=-I/home/shika/diplom/tests/C/testcasesupport -DOMITBAD"] # -DINCLUDEMAIN
        self.extra_bad = ["-cpp-extra-args=-I/home/shika/diplom/tests/C/testcasesupport -DOMITGOOD"] # -DINCLUDEMAIN

    def get_name(self):
        return "frama-c"

    def __get_file_name(self, file_path, suffix):
        base_name = os.path.splitext(os.path.basename(file_path))[0]
        return f"{base_name}_{suffix}"
    
    def __run_cmd(self, cmd):
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
        
        return {
            "raw_output": proc.stdout.strip() + proc.stderr.strip(),
            "runtime_sec": runtime
        }

    def run(self, file_path):
        cmd = ["frama-c"] + self.extra_args + self.main_func + [file_path]
        
        return self.__run_cmd(cmd)
    
    def run_good(self, file_path):
        cmd = ["frama-c"] + self.extra_args + self.extra_good + ["-main", self.__get_file_name(file_path, "good")] + [file_path]
        
        return self.__run_cmd(cmd)
    
    def run_bad(self, file_path):
        cmd = ["frama-c"] + self.extra_args + self.extra_bad + ["-main", self.__get_file_name(file_path, "bad")] + [file_path]
        
        return self.__run_cmd(cmd)
