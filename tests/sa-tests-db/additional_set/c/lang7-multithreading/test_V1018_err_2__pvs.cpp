// Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
// 
// Детектор обнаруживает отенциально возможную ошибку при использовании 
// обёртки над мьютексом (std::unique_lock и т.п.). 
// 
// Детектор PVS-Studio: https://pvs-studio.ru/ru/docs/warnings/v1018/

#include <memory>
#include <mutex>
#include <vector>
#include <iostream>
#include <thread>

namespace TestV1018_positive_2
{
  static std::mutex mutex;
  static std::vector<int> res;

  void TestV1018_positive()
  {
    std::unique_lock<std::mutex> lck(mutex, std::defer_lock); // FLAW
    if (res.empty())
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
    std::thread t1 { &TestV1018_positive };
    std::thread t2 { &TestV1018_positive };
    t1.join();
    t2.join();
  }
}