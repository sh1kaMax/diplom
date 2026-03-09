import os
import json
import psycopg2
from glob import glob

# Конфиг подключения к PostgreSQL
DB_HOST = "localhost"
DB_PORT = 5432
DB_NAME = "test_results"
DB_USER = "grafana_user"
DB_PASS = "grafana_pass"

# Путь к папке с JSON файлами
JSON_DIR = "../results/"  # можно указать путь к файлам

# Подключение к базе
conn = psycopg2.connect(
    host=DB_HOST,
    port=DB_PORT,
    dbname=DB_NAME,
    user=DB_USER,
    password=DB_PASS
)
cursor = conn.cursor()

# Создание таблицы (если не существует)
cursor.execute("""
CREATE TABLE IF NOT EXISTS analyzer_results (
    id SERIAL PRIMARY KEY,
    analyzer TEXT,
    test_type TEXT,
    correct_positive_tests INT,
    all_positive_tests INT,
    count_negative_tests INT,
    all_negative_tests INT,
    average_runtime FLOAT
)
""")
conn.commit()

# Очистка таблицы перед новой загрузкой
cursor.execute("TRUNCATE TABLE analyzer_results")
conn.commit()

# Чтение всех JSON файлов *_results.json
for file_path in glob(os.path.join(JSON_DIR, "*_results.json")):
    with open(file_path, "r") as f:
        data = json.load(f)
        analyzer = data.get("analyzer")
        tests_result = data.get("tests_result", {})
        
        for test_type, stats in tests_result.items():
            cursor.execute("""
                INSERT INTO analyzer_results (
                    analyzer, test_type, correct_positive_tests,
                    all_positive_tests, count_negative_tests,
                    all_negative_tests, average_runtime
                ) VALUES (%s, %s, %s, %s, %s, %s, %s)
            """, (
                analyzer,
                test_type,
                stats.get("correct_positive_tests"),
                stats.get("all_positive_tests"),
                stats.get("count_negative_tests"),
                stats.get("all_negative_tests"),
                stats.get("avarage_time_running_test")
            ))

conn.commit()
cursor.close()
conn.close()

print("Данные успешно загружены в PostgreSQL")
