/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 4) данные передаются через одну или несколько функций.

Детектор PVS-Studio: V774. Pointer was used after the memory was released.
Документация: https://pvs-studio.ru/ru/docs/warnings/v774/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v774/
*/

#include <iostream>

unsigned CalcAndDelete1(unsigned *p, size_t n)
{
  unsigned x = 0;
  for (size_t i = 0; i < n; i++)
  {
    x = x ^ p[i];
    p[i] = 0;
  }
  return x;
}

void ProcessArrErr1(unsigned *p, size_t n)
{
  unsigned u = CalcAndDelete1(p, n);
  if (n > 0)
    u &= p[0];
  std::cout << u;
}