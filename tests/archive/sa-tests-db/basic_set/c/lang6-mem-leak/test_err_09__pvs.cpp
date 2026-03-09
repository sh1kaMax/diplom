/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. е) Ошибки утечек памяти, незакрытых файловых дескрипторов и дескрипторов сетевых соединений.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 4) циклы с линейным изменением индуктивных переменных;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V773. Function exited without releasing the pointer/handle. A memory/resource leak is possible.
Документация: https://pvs-studio.ru/ru/docs/warnings/v773/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v773/
*/

#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include <cstdint>
#include <memory>
#include <stdio.h>
#include <string.h>

void arr_nop(int *, size_t) {}

int LoopLeakErr(size_t *src, size_t n)
{
  int *ptr = NULL;
  for (size_t i = 0; i != n; ++i)
  {
    ptr = (int *)malloc(src[i] * sizeof(int)); // FLAW
    if (ptr == NULL)
      return -1;
    arr_nop(ptr, src[i]);
  }
  free(ptr);
  return 0;
};