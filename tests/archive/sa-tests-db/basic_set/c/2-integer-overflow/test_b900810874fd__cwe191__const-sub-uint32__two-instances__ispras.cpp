// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-uint32.json
//
// Беззнаковое значение задается с помощью константы 0.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
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
  uint32_t data = 1;
  uint32_t result;

  SomeClass *cl_var1 = new SomeClass(27);
  SomeClass *cl_var2 = new SomeClass(-69);

  data = 0;

  if (cl_var2->getVal() > -63) {
    result = data - 1;
  }

  delete cl_var1;
  delete cl_var2;
}
