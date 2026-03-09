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

class User2
{
public:
  User2(std::string name, size_t id)
    : m_name { std::move(name) }
    , m_id { id } {}
public:
  User2(const User2 &) = default;
  User2(User2 &&) = default;
  User2 &operator=(const User2 &) = default;
  User2 &operator=(User2 &&) = default;
private:
  std::string m_name;
  size_t m_id;
};

void do_smth(const User2 *);
bool predicate();

void Err1_MemoryLeak()
{
  auto user = new User2("Petr Petrov", 2);
  if (!predicate()) return;               // FLAW

  do_smth(user);
  delete user;
}