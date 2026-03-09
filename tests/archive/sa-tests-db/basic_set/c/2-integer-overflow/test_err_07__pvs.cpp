/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. б) Ошибки целочисленного переполнения и некорректного совместного использования знаковых и беззнаковых чисел.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V784. The size of the bit mask is less than the size of the first operand. This will cause the loss of higher bits.
Документация: https://pvs-studio.ru/ru/docs/warnings/v784/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v784/
*/

#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <cstring>
#include <optional>
#include <cstdint>

uint64_t ErrGet32(uint64_t hold, unsigned bits)
{
  hold &= (1U << bits) - 1; // FLAW
  return hold;
}