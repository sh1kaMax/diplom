import subprocess
import time

class SplintAnalyzer:
    def __init__(self, extra_args=None):
        self.extra_args = extra_args or [
            "+bounds",
            "+strict",
            "+memchecks",
            "+usedef",
            "-I/home/shika/diplom/analyzers_runner_util/include",
            # "+matchanyintegral"
        ]

    def get_name(self):
        return "splint"

    def run(self, file_path):
        start = time.time()
        cmd = ["splint"] + self.extra_args + [file_path]

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
