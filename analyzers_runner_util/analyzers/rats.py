import subprocess
import time
from analyzers.abstract_analyzer import AbstractAnalyzer

class RATSAnalyzer(AbstractAnalyzer):
    def __init__(self, extra_args=None):
        self.extra_args = extra_args or ["-w", "3", "--language", "c"]

    def get_name(self):
        return "rats"

    def __run_cmd(self, cmd):
        start = time.time()
        
        try:
            proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, timeout=10)
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
        cmd = ["rats"] + self.extra_args + [file_path]
        
        return self.__run_cmd(cmd)

    def run_good(self, file_path):
        cmd = ["rats"] + self.extra_args + [file_path]
        
        return self.__run_cmd(cmd)

    def run_bad(self, file_path):
        cmd = ["rats"] + self.extra_args + [file_path]
        
        return self.__run_cmd(cmd)
