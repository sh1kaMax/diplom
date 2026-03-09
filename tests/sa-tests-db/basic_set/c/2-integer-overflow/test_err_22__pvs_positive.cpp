/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. б) Ошибки целочисленного переполнения и некорректного совместного использования знаковых и беззнаковых чисел.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 4) данные передаются через одну или несколько функций.

Детектор PVS-Studio: V1083. Signed integer overflow in arithmetic expression. This leads to undefined behavior.
Документация: https://pvs-studio.ru/ru/docs/warnings/v1083/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v1083/
*/

#include <iostream>
#include <limits.h>

int ErrUse6(bool b)
{
  if (b)
    return 10;
  else
    return 1;
}

int ErrGet44()
{
  int x = INT_MAX / 5;
  return ErrUse6(true) * x; // FLAW
}
