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

namespace TestV1036_negative_1
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
    SomeResource& TestV1036_negative();
  private:
    static std::mutex mtx;
    std::atomic<SomeResource *> m_res { nullptr };
  };

  SomeResource& TestClass::TestV1036_negative()
  {
    auto tmp = m_res.load(std::memory_order_acquire);
    if (!tmp)
    {
      std::lock_guard lock(mtx);
      tmp = m_res.load(std::memory_order_relaxed);
      if (!tmp)
      {
        tmp = new SomeResource();
        m_res.store(tmp, std::memory_order_release);
      }
    }

    return *tmp;
  }
}
