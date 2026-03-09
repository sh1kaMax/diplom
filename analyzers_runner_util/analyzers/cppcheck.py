import subprocess
import time

class CppcheckAnalyzer:
    def __init__(self, extra_args=None):
        self.extra_args = extra_args or [
            "--enable=all",
            "--quiet",
            "--inconclusive",
            "--force",
            "-I", "/home/shika/diplom/analyzers_runner_util/include"
        ]

    def get_name(self):
        return "cppcheck"

    def run(self, file_path):
        start = time.time()

        cmd = ["cppcheck"] + self.extra_args + [file_path]

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
