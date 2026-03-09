/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V641. Buffer size is not a multiple of element size.
Документация: https://pvs-studio.ru/ru/docs/warnings/v641/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v641/
*/

#include <iostream>
#include <cstdlib>

typedef unsigned short MYWCHAR;

MYWCHAR *Ok7(MYWCHAR *data16, int data16len)
{
  if (!data16)
  {
    data16 = (MYWCHAR*)calloc(data16len + 1, sizeof(MYWCHAR));
  }
  return data16;
}