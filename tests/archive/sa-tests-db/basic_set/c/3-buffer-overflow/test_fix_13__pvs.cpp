/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. в) Ошибки переполнения буфера (записи или чтения за пределами выделенной для буфера памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 4) циклы с линейным изменением индуктивных переменных;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V781. Value of a variable is checked after it is used. Possible error in program's logic. Check lines: N1, N2.
Документация: https://pvs-studio.ru/ru/docs/warnings/v781/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v781/
*/

#include <iostream>
#include <array>

void CheckIntAfterUseOk(int *arr, const int size)
{
  for (int i = 0; i < size && arr[i] < 10; ++i)
    arr[i] = 0;
}