/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. г) Ошибки использования форматной строки.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V618. Dangerous call of 'Foo' function. The passed line may contain format specification. 
Документация: https://pvs-studio.ru/ru/docs/warnings/v618/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v618/
*/

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>

#define lengthVar(cont) ( sizeof(cont) / sizeof(cont[0]) )

size_t my_read1(const char *res, char *buf, size_t max_len);

void Ok11(FILE *file)
{
  char buffer[1001];
  size_t len;
  while ((len = my_read1("some_resource_name", buffer, lengthVar(buffer) - 1)) > 0)
  {
    buffer[len] = 0;
    fprintf(file, "%s", buffer);
  }
}