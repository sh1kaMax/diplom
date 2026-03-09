// Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
// 
// Детектор обнаруживает  ситуацию, при которой объект типа 'std::scoped_lock'
// конструируется без переданных ему аргументов, т.е. без захвата объектов блокировки.
// 
// Детектор PVS-Studio: https://pvs-studio.ru/ru/docs/warnings/v1088/

#include <thread>
#include <mutex>

namespace TestV1088_negative_1
{
  int state = 0;
  std::mutex mutex1;

  void do_smth(int);

  void TestV1088_negative(int i)
  {
    std::scoped_lock lock(mutex1);
    state += i;
    do_smth(state);
  }

  void ExploitFlaw()
  {
    std::thread t1 { &TestV1088_negative,  0 };
    std::thread t2 { &TestV1088_negative, 10 };
    t1.join();
    t2.join();
  }
}