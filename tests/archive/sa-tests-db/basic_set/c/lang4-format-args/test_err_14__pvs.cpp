/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. г) Ошибки использования форматной строки.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V576. Incorrect format. Consider checking the Nth actual argument of the 'Foo' function.
Документация: https://pvs-studio.ru/ru/docs/warnings/v576/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v576/
*/

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
#include <cwchar>
#include <cstring>

#define STRING_MACROS_1 "%s"

void Err_NullPtrPrn1(const char *src)
{
  const char *f = STRING_MACROS_1;
  char *dup = strdup(src);
  if (!dup)
  {
    printf("Error copy string: " STRING_MACROS_1, dup); // FLAW
    return;
  }
  printf(f, dup);
  free(dup);
}