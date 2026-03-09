/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. а) Ошибки разыменования нулевого указателя.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V595. Pointer was used before its check for nullptr. Check lines: N1, N2.
Документация: https://pvs-studio.ru/ru/docs/warnings/v595/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v595/
*/

#include <iostream>

int _gdk_x11_screen_get_edge_monitors_ok(
  int *top, int *bottom, int a, int b)
{
  if (top)
  {
    *top = -1;
    if (a == 33)
      return 1;
  }
  if (bottom)
  {
    *bottom = -1;
    if (b == 22)
      return 2;
  }
  return 0;
}