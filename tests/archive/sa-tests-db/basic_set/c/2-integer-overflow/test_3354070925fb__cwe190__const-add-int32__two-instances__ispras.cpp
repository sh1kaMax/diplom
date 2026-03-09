// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int32.json
//
// Знаковое значение задается с помощью константы INT_MAX.
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
  int32_t data = 0;
  int32_t result;

  SomeClass *cl_var1 = new SomeClass(60);
  SomeClass *cl_var2 = new SomeClass(-55);

  data = INT_MAX;

  if (cl_var2->getVal() > -48) {
    result = data + 1;
  }

  delete cl_var1;
  delete cl_var2;
}
