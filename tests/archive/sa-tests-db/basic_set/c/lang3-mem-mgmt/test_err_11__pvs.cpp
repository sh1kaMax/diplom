/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 4) данные передаются через одну или несколько функций.

Детектор PVS-Studio: V611. Memory allocation and deallocation methods are incompatible.
Документация: https://pvs-studio.ru/ru/docs/warnings/v611/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v611/
*/

#include <iostream>
#include <map>
#include <memory>
#include <cstdio>

int *Alloc(size_t N)
{
  int *p = (int *)malloc(sizeof(int) * N);
  if (!p)
    return NULL;
  for (size_t i = 0; i < N; i++)
    p[i] = 1;
  return p;
}

void DelArr(int *p)
{
  delete [] p;
}

void Err4()
{
  int *p = Alloc(10);
  if (p)
  {
    printf("%p", p);
    DelArr(p); // FLAW
  }
}