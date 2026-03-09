/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. в) Ошибки переполнения буфера (записи или чтения за пределами выделенной для буфера памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V518. The 'malloc' function allocates suspicious amount of memory calculated by 'strlen(expr)'. Perhaps the correct expression is strlen(expr) + 1.
Документация: https://pvs-studio.ru/ru/docs/warnings/v518/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v518/
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

char *CopyStrErr(const char *src)
{
  char *p = (char *)malloc(strlen(src)); // FLAW
  if (!p)
    return p;
  strcpy(p, src);
  return p;
}