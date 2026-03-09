// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 78; }

template <> unsigned int get_template<float>(float c) { return -40; }

void func(void) {
  char format[44] = "Initial format string";

  int local_var1 = 78;

  if (local_var1 > 57) {
    scanf("%43s", format);
  }

  if (get_template(0.33) > 57) {
    printf(format);
  }
}
