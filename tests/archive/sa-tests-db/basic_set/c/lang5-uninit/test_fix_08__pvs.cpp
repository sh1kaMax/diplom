/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. д) Ошибки использования неинициализированных переменных.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
  6.7. a) 4) циклы с линейным изменением индуктивных переменных;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
  6.7.1. б) 3) данные передаются через сложные структуры данных (списки, коллекции и т. п.).

Детектор PVS-Studio: V614. Use of 'Foo' uninitialized variable.
Документация: https://pvs-studio.ru/ru/docs/warnings/v614/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v614/
*/

#include <iostream>
#include <array>
#include <algorithm>

typedef double Type;
constexpr size_t Size = 3;

Type FixGet5()
{
  std::array<Type, Size> arr;
  std::fill(std::begin(arr), std::end(arr), 1.1);
  Type sum = 0;
  for (size_t i = 0; i < arr.size(); ++i)
    sum += arr[i];
  return sum;
}