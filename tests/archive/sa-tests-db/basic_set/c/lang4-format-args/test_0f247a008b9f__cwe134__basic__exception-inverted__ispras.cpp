// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

class ExceptionClass {};

void func(void) {
  char format[44] = "Initial format string";

  try {
    printf(format);
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    scanf("%43s", format);
  }
}
