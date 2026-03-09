// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 11; }

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int divident = 28, divisor = 8, result;

  SomeClass *cl_var1 = new SomeClass(28);
  SomeClass *cl_var2 = new SomeClass(-19);

  divisor = 0;

  if (cl_var1->getVal() > 26) {
    result = wrapper(divisor);
  }

  delete cl_var1;
  delete cl_var2;
}
