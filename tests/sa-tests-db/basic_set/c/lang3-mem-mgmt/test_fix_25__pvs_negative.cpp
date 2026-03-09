/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 5) сложные циклы, вложенные циклы;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V774. Pointer was used after the memory was released.
Документация: https://pvs-studio.ru/ru/docs/warnings/v774/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v774/
*/

#include <iostream>

struct NodeCpp1
{
  NodeCpp1 *next;
  float x;
};

void CppClearListOk(NodeCpp1 *head)
{
NodeCpp1 *p = head;
  while (p != nullptr)
  {
    NodeCpp1 *prev = p;
    p = p->next;
    delete prev;
  }
}