/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V586. The 'Foo' function is called twice to deallocate the same resource.
Документация: https://pvs-studio.ru/ru/docs/warnings/v586/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v586/
*/

#include <iostream>
#include <memory>

void Err1(size_t N, size_t K)
{
  float *p1 = (float *)malloc(N * sizeof(float));
  if (!p1) return;
  float *p2 = (float *)malloc(K * sizeof(float));
  if (!p2)
  {
    free(p1);
    return;
  }
  std::cout << p1 << p2 << std::endl;
  free(p1);
  free(p1); // FLAW
  free(p2);
}