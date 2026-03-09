/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. е) Ошибки утечек памяти, незакрытых файловых дескрипторов и дескрипторов сетевых соединений.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V1023. A pointer without owner is added to the container by the 'emplace_back' method. A memory leak will occur in case of an exception.
Документация: https://pvs-studio.ru/ru/docs/warnings/v1023/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v1023/
*/

#include <cstddef>
#include <vector>
#include <memory>
#include <string>

template <typename T>
using ResultType = std::vector<std::unique_ptr<T>>;

class User1
{
public:
  User1(size_t id, std::string name)
    : m_id { id }
    , m_name { std::move(name) }
  {
  }

  User1(const User1 &) = default;
  User1(User1 &&) = default;
  User1 &operator=(const User1 &) = default;
  User1 &operator=(User1 &&) = default;
private:
  size_t m_id;
  std::string m_name;
};

using ResultType_NonPOD = ResultType<User1>;

auto Ok2_NonPOD_Type_Variant1()
{
  ResultType_NonPOD res;
  res.emplace_back(std::make_unique<User1>(1, "Ivan Ivanov"));
  return res;
}