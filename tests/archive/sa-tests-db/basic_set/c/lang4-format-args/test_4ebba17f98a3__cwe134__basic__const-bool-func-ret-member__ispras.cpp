// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: const-bool-func-ret-member.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// значение члена класса. Значение устанавливается вначале в true, затем в
// false.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

class SomeClass {
  bool member_flag;

public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return member_flag; }

void SomeClass::func(void) {
  char format[70] = "Initial format string";

  member_flag = true;

  scanf("%69s", format);

  member_flag = false;

  if (isTrue()) {
    printf(format);
  }
}
