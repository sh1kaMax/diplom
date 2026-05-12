import sys
import os
import json
from analyzers_handler import AnalyzersHandler
from concurrent.futures import ThreadPoolExecutor

def collect_tests(path):
    tests = []

    for root, _, files in os.walk(path):
        for f in files:
            if f.endswith(".c"):
                path = os.path.join(root, f)
                tests.append(path)

    return tests

def check_test_result(result, is_pos, accepted_errs):
    if is_pos:
        for check_err in accepted_errs:
            if check_err in result["raw_output"]:
                return True
        return False
    else:
        for check_err in accepted_errs:
            if check_err in result["raw_output"]:
                return False
        return True

def run_tests(analyzer, tests, accepted_errors):
    results = []
    all_positive_tests_count = 0
    correct_positive_tests_count = 0
    all_negative_tests_count = 0
    correct_negative_tests_count = 0

    for t in tests:
        is_positive_test = "positive" in t
        is_negative_test = "negative" in t
        is_double_test = not (is_positive_test or is_negative_test)

        all_positive_tests_count += 1 if ("positive" in t) or is_double_test else 0
        all_negative_tests_count += 1 if ("positive" not in t) or is_double_test else 0
        
        if is_double_test:
            res_good = analyzer.run_good(t)
            good_passed = check_test_result(res_good, False, accepted_errors)
            
            res_bad = analyzer.run_bad(t)
            bad_passed = check_test_result(res_bad, True, accepted_errors)
            
            if bad_passed:
                correct_positive_tests_count += 1
            if good_passed:
                correct_negative_tests_count += 1

            results.append({
                "file": t,
                "test_completed_right": good_passed,
                "is_positive_test": False,
                "runtime_sec": res_good["runtime_sec"],
                "output": res_good["raw_output"],
            })

            results.append({
                "file": t,
                "test_completed_right": bad_passed,
                "is_positive_test": True,
                "runtime_sec": res_bad["runtime_sec"],
                "output": res_bad["raw_output"],
            })
            
            
        else:
            res = analyzer.run(t)
            passed = check_test_result(res, is_positive_test, accepted_errors)
            
            if passed:
                if is_positive_test:
                    correct_positive_tests_count += 1
                else:
                    correct_negative_tests_count += 1

            results.append({
                "file": t,
                "test_completed_right": passed,
                "is_positive_test": is_positive_test,
                "runtime_sec": res["runtime_sec"],
                "output": res["raw_output"],
            })

    return results, all_positive_tests_count, correct_positive_tests_count, all_negative_tests_count, correct_negative_tests_count

def run_test_type(analyzer, test, output_dir):
    tests = collect_tests(test["path"])
    accepted_errors = test["analyzers"].get(analyzer.get_name(), {}).get("accepted_errors", [])
    results, count_positive, correct_positive, count_negative, correct_negative = run_tests(analyzer, tests, accepted_errors)
    
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

def run_analyzer(analyzer_name, config, analyzer_handler, spec_err):
    print(f"Проверка {analyzer_name}")
    analyzer = analyzer_handler.get_analyzer_by_name(analyzer_name)
    tests_to_run = []

    if spec_err is not None:
        for test in config["tests"]:
            if test["name"] == spec_err:
                tests_to_run.append(test)
    else:
        tests_to_run = config["tests"]

    analyzer_dir = os.path.join("results", analyzer_name)
    os.makedirs(analyzer_dir, exist_ok=True)

    test_files = []
    with ThreadPoolExecutor(max_workers=len(config["tests"])) as test_executor:
        futures = [test_executor.submit(run_test_type, analyzer, test, analyzer_dir)
                   for test in tests_to_run]
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
    specific_analyzer = None
    specific_err = None
    if len(sys.argv) > 1:
        specific_analyzer = sys.argv[1]

    if len(sys.argv) > 2:
        specific_err = sys.argv[2]

    with open("analyzers_runner_util/test_configs.json") as f:
        config = json.load(f)

    if specific_analyzer:
        if specific_analyzer not in config["analyzers_all"] and specific_analyzer != "all":
            print(f"Ошибка: Анализатора '{specific_analyzer}' нету в конфигурационном файле")
            print(f"Доступные анализаторы: {', '.join(config['analyzers_all'])}")
            sys.exit(1)

        if specific_analyzer == "all":
            analyzers_to_run = config["analyzers_all"]
        else:
            analyzers_to_run = [specific_analyzer]
    else:
        analyzers_to_run = config["analyzers_all"]

    analyzer_handler = AnalyzersHandler()

    with ThreadPoolExecutor(max_workers=len(config["analyzers_all"])) as executor:
        futures = [executor.submit(run_analyzer, analyzer_name, config, analyzer_handler, specific_err)
                   for analyzer_name in analyzers_to_run]
        for future in futures:
            future.result()

if __name__ == "__main__":
    main()
