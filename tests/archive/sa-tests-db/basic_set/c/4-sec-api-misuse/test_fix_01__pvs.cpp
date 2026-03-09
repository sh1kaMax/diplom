/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.3. г) Ошибки некорректного использования системных процедур и интерфейсов, связанных с обеспечением информационной безопасности (шифрования, разграничения доступа и пр.).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio:  V597. Compiler may delete 'memset' function call that is used to clear 'Foo' buffer. Use the RtlSecureZeroMemory() function to erase private data.
Документация: https://pvs-studio.ru/ru/docs/warnings/v597/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v597/
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>

void secure_zero(void *s, size_t n)
{
  volatile char *p = (volatile char *)s;
  while (n--) *p++ = 0;
}

int SensitiveClearOk_1(const char *pass)
{
  char sensitiveData[16];
  strcpy(sensitiveData, "password");
  int res = strcmp(sensitiveData, pass);
  secure_zero(sensitiveData, sizeof(sensitiveData));
  return res;
}