/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. е) Ошибки утечек памяти, незакрытых файловых дескрипторов и дескрипторов сетевых соединений.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V773. Function exited without releasing the pointer/handle. A memory/resource leak is possible.
Документация: https://pvs-studio.ru/ru/docs/warnings/v773/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v773/
*/

#include <cstddef>
#include <cstdio>
#include <string>
#include <memory>

class User3
{
public:
  User3(std::string name, size_t id)
    : m_name { std::move(name) }
    , m_id { id } {}
public:
  User3(const User3 &) = default;
  User3(User3 &&) = default;
  User3 &operator=(const User3 &) = default;
  User3 &operator=(User3 &&) = default;
private:
  std::string m_name;
  size_t m_id;
};

void do_smth_1(const User3 *);
bool predicate_1();

void Ok1_MemoryLeak()
{
  auto user = std::make_unique<User3>("Petr Petrov", 2);
  if (!predicate_1()) return;

  do_smth_1(user.get());
}