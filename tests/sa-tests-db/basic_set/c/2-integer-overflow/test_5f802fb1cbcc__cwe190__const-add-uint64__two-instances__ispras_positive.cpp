// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint64.json
//
// Беззнаковое значение задается с помощью константы ULLONG_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  uint64_t data = 0;
  uint64_t result;

  SomeClass *cl_var1 = new SomeClass(97);
  SomeClass *cl_var2 = new SomeClass(-93);

  data = ULLONG_MAX;

  if (cl_var1->getVal() > 93) {
    result = data + 1; // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
