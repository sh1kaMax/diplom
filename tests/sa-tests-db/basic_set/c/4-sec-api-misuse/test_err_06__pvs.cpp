/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.3. г) Ошибки некорректного использования системных процедур и интерфейсов, связанных с обеспечением информационной безопасности (шифрования, разграничения доступа и пр.).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 3) данные передаются через одну или несколько функций

Детектор PVS-Studio: V597. Compiler may delete 'memset' function call that is used to clear 'Foo' buffer. Use the RtlSecureZeroMemory() function to erase private data.
Документация: https://pvs-studio.ru/ru/docs/warnings/v597/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v597/
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

void SFree2(char *p)
{
  free(p);
}

void SensitiveClearErr_3()
{
  size_t n = 100;
  char *sensitiveData = (char *)malloc(n);
  if (sensitiveData)
  {
    strcpy(sensitiveData, "password");
    printf("%s", sensitiveData);
    memset(sensitiveData, 0, n); // FLAW
    SFree2(sensitiveData);
  }
}

