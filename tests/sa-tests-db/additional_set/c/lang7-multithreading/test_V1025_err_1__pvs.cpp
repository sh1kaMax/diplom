// Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
// 
// Детектор обнаруживает неправильное использование класса 'std::unique_lock',
// что может приводить к состоянию гонки.
// 
// Детектор PVS-Studio: https://pvs-studio.ru/ru/docs/warnings/v1025/

#include <mutex>
#include <vector>
#include <iostream>
#include <thread>

namespace TestV1025_positive_1
{
  static std::mutex mutex;
  static std::vector<int> res;

  void TestV1025_positive()
  {
    if (std::unique_lock<std::mutex>(mutex); res.empty()) // FLAW
    {
      for (size_t i = 0; i < 100; ++i)
      {
        res.push_back(i);
      }
    }
    else
    {
      for (auto elem : res)
      {
        std::cout << elem << std::endl;
      }
    }
  }

  void ExploitFlaw()
  {
    std::thread t1 { &TestV1025_positive };
    std::thread t2 { &TestV1025_positive };
    t1.join();
    t2.join();
  }
}
