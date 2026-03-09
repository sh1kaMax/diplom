import subprocess
import time
import os
import tempfile

class InferAnalyzer:
    def __init__(self, extra_args=None):
        self.extra_args = extra_args or [
            "run",
            "--",
            "gcc",
            "-Wall",
            "-Wextra",
            "-c",
            "-I/home/shika/diplom/analazers_runner_util/include"
        ]

    def get_name(self):
        return "infer"

    def run(self, file_path):
        start = time.time()
        
        with tempfile.TemporaryDirectory(prefix="infer_out_") as results_dir:
            cmd = ["infer", "--results-dir", results_dir] + self.extra_args + [file_path]
            
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

            subprocess.run("rm -f *.o", shell=True)

            runtime = time.time() - start

            return {
                "raw_output": proc.stdout.strip() + proc.stderr.strip(),
                "runtime_sec": runtime
            }
