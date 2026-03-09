/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. г) Ошибки использования форматной строки.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V541. String is printed into itself. Consider inspecting the expression.
Документация: https://pvs-studio.ru/ru/docs/warnings/v541/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v541/
*/

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
#include <memory>
#include <cstring>

char *Ok15(char *buf, size_t max)
{
  int i = 0;
  ++i;

  auto tmp = std::make_unique_for_overwrite<char[]>(max + 1);
  tmp[max] = '\0';

  ptrdiff_t len = snprintf(tmp.get(), max, "N = %d, S = %s", i, buf);
  if (len < 0) return buf;

  strcpy(buf, tmp.get());

  return buf;
}