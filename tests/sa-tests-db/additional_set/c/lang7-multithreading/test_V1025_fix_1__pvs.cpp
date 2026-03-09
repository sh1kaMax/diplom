// Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
// 
// Детектор обнаруживает неправильное использование класса 'std::unique_lock',
// что может приводить к состоянию гонки.
// 
// Детектор PVS-Studio: https://pvs-studio.ru/ru/docs/warnings/v1025/

#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

namespace TestV1025_negative_1
{
  static std::mutex mutex;
  static std::vector<int> res;

  void TestV1025_negative()
  {
    if (std::unique_lock<std::mutex> _(mutex); res.empty())
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

  void NoFlaw()
  {
    std::thread t1 { &TestV1025_negative };
    std::thread t2 { &TestV1025_negative };
    t1.join();
    t2.join();
  }
}
