/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. а) Ошибки разыменования нулевого указателя.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V522. Possible null pointer dereference.
Документация: https://pvs-studio.ru/ru/docs/warnings/v522/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v522/
*/

#include <iostream>
#include <array>

struct PND_Struct4
{
  int m_a;
  int m_arr[5];
};

int PotentialNullDeref_3_err(PND_Struct4 *p1, PND_Struct4 *p2)
{
  if (p1 == p2)
    return 1;
  if (p1)
    return 2;
  if (!p2)
    return 3;
  return p1->m_arr[1] < p2->m_arr[2]; // FLAW
}