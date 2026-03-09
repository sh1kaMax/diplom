/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio:  V748. Memory for 'getline' function should be allocated only by 'malloc' or 'realloc' functions. 
                      Consider inspecting the first parameter of 'getline' function.
Документация: https://pvs-studio.ru/ru/docs/warnings/v748/
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cstdint>
#include <limits.h>
#include <stdio.h>

#ifdef _WINDOWS
typedef ptrdiff_t ssize_t;
ssize_t getline(char** lineptr, size_t* n, FILE* stream);
#endif

char *Ok8(size_t n, FILE *stream)
{
  char* buf = (char *)malloc(sizeof(char) * n);
  if (buf)
    getline(&buf, &n, stream);
  return buf;
}