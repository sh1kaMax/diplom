/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. а) Ошибки разыменования нулевого указателя.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V713. Pointer was used in the logical expression before its check for nullptr in the same logical expression.
Документация: https://pvs-studio.ru/ru/docs/warnings/v713/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v713/
*/

#include <iostream>

bool UseBeforeCheckExr_err(int *arr)
{
  return arr[0] != 0 && arr != nullptr; // FLAW
}