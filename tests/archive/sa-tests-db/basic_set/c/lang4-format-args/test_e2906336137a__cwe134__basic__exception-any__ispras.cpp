// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

class ExceptionClass {};

void func(void) {
  char format[71] = "Initial format string";

  try {
    scanf("%70s", format);
    throw ExceptionClass();
  } catch (...) {
    printf(format); // FLAW
  }
}
