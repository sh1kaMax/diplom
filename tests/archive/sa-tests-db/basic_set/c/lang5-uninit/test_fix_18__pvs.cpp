/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. д) Ошибки использования неинициализированных переменных.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7.1. б) 3) данные передаются через сложные структуры данных (списки, коллекции и т. п.).

Детектор PVS-Studio: V1007. Value from the uninitialized optional is used. It may be an error.
Документация: https://pvs-studio.ru/ru/docs/warnings/v1007/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v1007/
*/

#include <iostream>
#include <optional>

struct Foo { int a; };
std::optional<Foo> bar();

int FixGet13()
{
  auto obj = bar();
  if (obj)
  {
    std::cout << "Ok: a = " << obj->a << std::endl;
  }
  return 0;
}