/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. е) Ошибки утечек памяти, незакрытых файловых дескрипторов и дескрипторов сетевых соединений.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 5) сложные циклы, вложенные циклы; 
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V701. Possible realloc() leak: when realloc() fails to allocate memory, original pointer is lost. Consider assigning realloc() to a temporary pointer.
Документация: https://pvs-studio.ru/ru/docs/warnings/v701/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v701/
*/

#include <iostream>
#include <cstring>
#include <cstdint>
#include <memory>
#include <stdio.h>
#include <string.h>
#include <string_view>

int ReallocLeak_ok(size_t n, size_t k)
{
  for (size_t i = 1; i < n; i++)
  {
    int *p = (int *)malloc(i);
    for (size_t j = 1; j < k; j++)
    {
      int *q = (int *)realloc(p, k);
      if (!q)
      {
        free(p);
        return -1;
      }
      p = q;
    }
    free(p);
  }
  return 0;
}   