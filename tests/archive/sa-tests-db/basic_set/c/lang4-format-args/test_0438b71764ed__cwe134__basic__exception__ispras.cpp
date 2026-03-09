// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

class ExceptionClass {};

void func(void) {
  char format[61] = "Initial format string";

  try {
    printf(format);
    throw ExceptionClass();
    scanf("%60s", format);
  } catch (const ExceptionClass &excpt) {
  }
}
