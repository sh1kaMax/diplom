import subprocess
import time

class FramaCAnalyzer:
    def __init__(self, extra_args=None):
        self.extra_args = extra_args or ["-eva", "-warn-signed-overflow", "-warn-unsigned-overflow"]
        self.main_func = ["-main", "func"]
        self.extra_pos = ["-cpp-extra-args=\"-I/home/shika/diplom/tests/C/testcasesupport -include alloca.h -DINCLUDEMAIN -DOMITBAD\"", "-main", "main"]
        self.extra_neg = ["-cpp-extra-args=\"-I/home/shika/diplom/tests/C/testcasesupport -include alloca.h -DINCLUDEMAIN -DOMITGOOD\"", "-main", "main"]

    def get_name(self):
        return "frama-c"
    
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
    
    def run_pos(self, file_path):
        cmd = ["frama-c"] + self.extra_args + self.extra_pos + [file_path]
        
        return self.__run_cmd(cmd)
    
    def run_neg(self, file_path):
        cmd = ["frama-c"] + self.extra_args + self.extra_neg + [file_path]
        
        return self.__run_cmd(cmd)
