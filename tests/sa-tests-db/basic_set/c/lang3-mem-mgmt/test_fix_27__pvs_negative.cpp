/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V774. Pointer was used after the memory was released.
Документация: https://pvs-studio.ru/ru/docs/warnings/v774/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v774/
*/

#include <iostream>
#include <cstdlib>

struct UAFStructC1
{
  int m_a, m_b;
};

int OkUAF()
{
  UAFStructC1 *ptr = (UAFStructC1 *)malloc(sizeof(UAFStructC1));
  if (ptr == NULL)
    return -1;
  ptr->m_a = rand();
  if (ptr->m_a > 100)
  {
    int v = ptr->m_a / 10;
    free(ptr);
    return v;
  }
  int v = ptr->m_a / 2;
  free(ptr);
  return v;
}