// Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
// 
// Детектор обнаруживает потенциально возможную ошибку, 
// связанную с небезопасным использованием паттерна 
// "блокировки с двойной проверкой" (double checked locking).
// 
// Детектор PVS-Studio: https://pvs-studio.ru/ru/docs/warnings/v1036/
// Примеры реальных ошибок : https://pvs-studio.ru/ru/blog/examples/v1036/

#include <mutex>
#include <atomic>

namespace TestV1036_positive_1
{
  class SomeResource 
  {
  public:
    SomeResource() noexcept;
  
  private:
    int descr;
  };

  class TestClass
  {
  public:
    SomeResource &TestV1036_positive();
  private:
    static std::mutex mtx;
    SomeResource *m_res = nullptr;
  };

  SomeResource &TestClass::TestV1036_positive()
  {
    if (!m_res)
    {
      std::lock_guard lock(mtx);
      if (!m_res) // FLAW
      {
        m_res = new SomeResource();
      }
    }

    return *m_res;
  }
}
