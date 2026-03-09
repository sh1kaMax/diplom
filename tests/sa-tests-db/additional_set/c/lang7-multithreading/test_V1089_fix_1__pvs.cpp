// Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
// 
// Детектор обнаруживает ситуацию, в которой одна из нестатических функций-членов класса
// 'std::condition_variable' – 'wait', 'wait_for' или 'wait_until' – вызывается без предиката.
// 
// Детектор PVS-Studio: https://pvs-studio.ru/ru/docs/warnings/v1089/
// Примеры реальных ошибок : https://pvs-studio.ru/ru/blog/examples/v1089/

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace TestV1089_negative_1
{
  namespace TestV1089_negative
  {
    std::queue<int> queue;
    std::mutex mtx;
    std::condition_variable cond;

    void do_smth(int);

    void consumer()
    {
      while (true)
      {
        int var;

        {
          using namespace std::literals;
          std::unique_lock<std::mutex> lck { mtx };
          bool res = cond.wait_for(lck,
                                   std::chrono::seconds(10),
                                   [] { return !queue.empty(); });
          if (!res)
          {
            break;
          }

          var = queue.front();
          queue.pop();
        }

        do_smth(var);
      }
    }

    void producer(std::istream &in)
    {
      int var;
      while (in >> var)
      {
        {
          std::lock_guard<std::mutex> _{ mtx };
          queue.push(var);
        }

        cond.notify_one();
      }
    }

    void NoFlaw(std::ifstream &fin, std::istringstream &sin)
    {
      std::thread p1 { &producer, std::ref(fin) };
      std::thread p2 { &producer, std::ref(sin) };
      std::thread p3 { &producer, std::ref(std::cin) };

      std::thread c1 { &consumer };
      std::thread c2 { &consumer };
      std::thread c3 { &consumer };

      p1.join(); p2.join(); p3.join();
      c1.join(); c2.join(); c3.join();
    }
  }
}