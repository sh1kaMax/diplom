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

struct PND_Struct2
{
  int m_a;
  int m_arr[5];
};

#define TEST_MACROS_IF_NULL(ptr) ((ptr) == NULL)

int PotentialNullDeref_2_err(PND_Struct2 *pointer)
{
  if (TEST_MACROS_IF_NULL(pointer) && pointer->m_a) // FLAW
    return 1;
  return 0;  
}
