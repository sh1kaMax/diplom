/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. б) Ошибки целочисленного переполнения и некорректного совместного использования знаковых и беззнаковых чисел.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio:  V1081. Argument of abs() function is minimal negative value. 
                      Such absolute value can't be represented in two's complement. This leads to undefined behavior.
Документация: https://pvs-studio.ru/ru/docs/warnings/v1081/
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <optional>
#include <cstdint>
#include <limits.h>

unsigned ErrGet37()
{
  int min = INT_MIN;
  return std::abs(min); // FLAW
}