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

namespace TestV1018_negative_1
{
  static std::vector<int> res;
  static std::mutex res_mutex;

  void TestV1018_negative()
  {
    std::unique_lock<std::mutex> lck(res_mutex);
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

  void NoFlaw()
  {
    std::thread t1 { &TestV1018_negative };
    std::thread t2 { &TestV1018_negative };
    t1.join();
    t2.join();
  }
}