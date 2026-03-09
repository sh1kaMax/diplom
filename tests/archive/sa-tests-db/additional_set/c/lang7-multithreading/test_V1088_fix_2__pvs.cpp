// Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
// 
// Детектор обнаруживает  ситуацию, при которой объект типа 'std::scoped_lock'
// конструируется без переданных ему аргументов, т.е. без захвата объектов блокировки.
// 
// Детектор PVS-Studio: https://pvs-studio.ru/ru/docs/warnings/v1088/

#include <thread>
#include <mutex>

namespace TestV1088_negative_2
{
  int state = 0;
  void do_smth(int);

  class TestClass
  {
  public:
    TestClass(int &state)
      : m_ptr { &state }
      , m_lock { m_mutex }
    {
    }

    void ModifyAndEvaluate(int i) const
    {
      *m_ptr += i;
      do_smth(i);
    }

  private:
    static std::mutex m_mutex;
    int *m_ptr;
    std::scoped_lock<std::mutex> m_lock;
  };

  void ExploitFlaw()
  {
    constexpr auto func = [](int i) { TestClass obj { state }; obj.ModifyAndEvaluate(i); };
    std::thread t1 { func,   0 };
    std::thread t2 { func, 100 };
    t1.join();
    t2.join();
  }
}
