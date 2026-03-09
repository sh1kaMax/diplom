import os
import json
from analyzers_handler import AnalyzersHandler
from concurrent.futures import ThreadPoolExecutor

def collect_tests(path):
    tests = []

    for root, _, files in os.walk(path):
        for f in files:
            if f.endswith(".c") or f.endswith(".cpp"):
                path = os.path.join(root, f)
                tests.append(path)

    return tests

def evaluate(analyzer, tests, accepted_errors):
    results = []
    all_positive_tests_count = 0
    correct_positive_tests_count = 0
    all_negative_tests_count = 0
    correct_negative_tests_count = 0

    for t in tests:
        is_positive_test = True if "positive" in t else False
        all_positive_tests_count += 1 if "positive" in t else 0
        all_negative_tests_count += 1 if "positive" not in t else 0
        
        res = analyzer.run(t)
        flag = False
        count_checked_negative_errs = 0

        for check_err in accepted_errors:
            if (check_err in res["raw_output"] and "positive" in t):
                correct_positive_tests_count += 1
                flag = True
                break
            elif (check_err not in res["raw_output"] and "negative" in t):
                count_checked_negative_errs += 1

        if ("negative" in t and count_checked_negative_errs == len(accepted_errors)):
            correct_negative_tests_count += 1
            flag = True

        results.append({
            "file": t,
            "test_complited_right": flag,
            "is_positive_test": is_positive_test,
            "runtime_sec": res["runtime_sec"],
            "output": res["raw_output"],
        })

    return results, all_positive_tests_count, correct_positive_tests_count, all_negative_tests_count, correct_negative_tests_count

def run_test_type(analyzer, test, output_dir):
    tests = collect_tests(test["path"])
    accepted_errors = test["analyzers"].get(analyzer.get_name(), {}).get("accepted_errors", [])
    results, count_positive, correct_positive, count_negative, correct_negative = evaluate(analyzer, tests, accepted_errors)
    
    test_file = os.path.join(output_dir, f"{test['name']}_results.json")
    with open(test_file, "w") as f:
        json.dump({
            "results": results,
            "summary": {
                "correct_positive_tests": correct_positive,
                "all_positive_tests": count_positive,
                "count_negative_tests": correct_negative,
                "all_negative_tests": count_negative
            }
        }, f, indent=4)
    return test_file

def run_analyzer(analyzer_name, config, analyzer_handler):
    print(f"Проверка {analyzer_name}")
    analyzer = analyzer_handler.get_analyzer_by_name(analyzer_name)

    analyzer_dir = os.path.join("results", analyzer_name)
    os.makedirs(analyzer_dir, exist_ok=True)

    test_files = []
    with ThreadPoolExecutor(max_workers=len(config["tests"])) as test_executor:
        futures = [test_executor.submit(run_test_type, analyzer, test, analyzer_dir)
                   for test in config["tests"]]
        for future in futures:
            test_files.append(future.result())

    final_results = {"analyzer": analyzer_name, "tests_result": {}}
    for test_file in test_files:
        with open(test_file) as f:
            data = json.load(f)
            test_name = os.path.basename(test_file).replace("_results.json", "")
            final_results["tests_result"][test_name] = data["summary"]

    final_file = os.path.join(analyzer_dir, f"{analyzer_name}_all_results.json")
    with open(final_file, "w") as f:
        json.dump(final_results, f, indent=4)

    print(f"Готово! Результаты сохранены в {final_file}")

def main():
    with open("analyzers_runner_util/test_configs.json") as f:
        config = json.load(f)

    analyzer_handler = AnalyzersHandler()

    with ThreadPoolExecutor(max_workers=len(config["analyzers_all"])) as executor:
        futures = [executor.submit(run_analyzer, analyzer_name, config, analyzer_handler)
                   for analyzer_name in config["analyzers_all"]]
        for future in futures:
            future.result()

if __name__ == "__main__":
    main()
