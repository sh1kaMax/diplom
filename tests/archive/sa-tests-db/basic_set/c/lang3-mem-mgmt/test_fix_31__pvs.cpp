/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7.1. б) 3) данные передаются через сложные структуры данных (списки, коллекции и т. п.).

Детектор PVS-Studio: V1006. Several shared_ptr objects are initialized by the same pointer. A double memory deallocation will occur.
Документация: https://pvs-studio.ru/ru/docs/warnings/v1002/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v1002/
*/

#include <iostream>
#include <memory>

int SharedPtrDoubleFreeOk()
{
  struct S { int a, b; };
  S *rawPtr = new S{10, 20};
  std::shared_ptr<S> shared1(rawPtr);
  shared1->a++;
  std::shared_ptr<S> shared2(new S(*rawPtr));
  shared2->b--;
  return shared1->a + shared2->b;
}