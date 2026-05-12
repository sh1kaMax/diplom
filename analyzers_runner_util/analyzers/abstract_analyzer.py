from abc import ABC, abstractmethod

class AbstractAnalyzer(ABC):

    @abstractmethod
    def get_name(self) -> str:
        """Вернуть имя анализатора (как в конфигурационном файле)."""
        pass

    @abstractmethod
    def run(self, file_path: str) -> dict:
        """
        Запуск анализа одиночного файла (универсальная версия).
        Должен вернуть dict:
        {
            "raw_output": str,
            "runtime_sec": float
        }
        """
        pass

    def run_good(self, file_path: str) -> dict:
        """
        Запуск негативного теста из тестового набора, где в одном файле сразу два теста.
        Должен вернуть dict:
        {
            "raw_output": str,
            "runtime_sec": float
        }
        """
        return self.run(file_path)

    def run_bad(self, file_path: str) -> dict:
        """
        Запуск позитивного теста из тестового набора, где в одном файле сразу два теста.
        Должен вернуть dict:
        {
            "raw_output": str,
            "runtime_sec": float
        }
        """
        return self.run(file_path)