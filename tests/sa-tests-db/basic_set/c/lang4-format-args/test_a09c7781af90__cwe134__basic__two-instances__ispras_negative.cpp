// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  char format[35] = "Initial format string";

  SomeClass *cl_var1 = new SomeClass(85);
  SomeClass *cl_var2 = new SomeClass(-9);

  scanf("%34s", format);

  if (cl_var2->getVal() > -7) {
    printf(format);
  }

  delete cl_var1;
  delete cl_var2;
}
