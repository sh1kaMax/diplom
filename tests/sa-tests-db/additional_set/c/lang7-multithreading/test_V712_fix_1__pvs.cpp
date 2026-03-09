// Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
// 
// Детектор обнаруживает в коде цикл с пустым телом, 
// который может быть превращён компилятором после оптимизации 
// в вечный цикл или убран из кода программы. 
// 
// Детектор PVS-Studio: https://pvs-studio.ru/ru/docs/warnings/v712/
// Примеры реальных ошибок : https://pvs-studio.ru/ru/blog/examples/v712/

#include <thread>
#include <chrono>
#include <atomic>

namespace TestV712_negative_1
{
  class ThreadData
  {
  public:
    ThreadData() = default;
    std::atomic_bool kill { false }, dead { false };
  };

  void TestV712_negative(ThreadData *threadData)
  {
    threadData->kill.store(true, std::memory_order_release);
    while (!threadData->dead.load(std::memory_order_acquire));
  }
}