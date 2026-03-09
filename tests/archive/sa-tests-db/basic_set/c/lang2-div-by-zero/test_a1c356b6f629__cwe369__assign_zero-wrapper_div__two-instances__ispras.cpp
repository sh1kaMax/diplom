// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1751 / wrapper_par; }

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int divident = 63, divisor = 7, result;

  SomeClass *cl_var1 = new SomeClass(80);
  SomeClass *cl_var2 = new SomeClass(-13);

  divisor = 0;

  if (cl_var2->getVal() > -9) {
    result = wrapper(divisor);
  }

  delete cl_var1;
  delete cl_var2;
}
