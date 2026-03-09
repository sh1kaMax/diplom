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

int wrapper(int wrapper_par) { return 1254 / wrapper_par; }

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int divident = 21, divisor = 10, result;

  SomeClass *cl_var1 = new SomeClass(82);
  SomeClass *cl_var2 = new SomeClass(-11);

  divisor = 0;

  if (cl_var1->getVal() > 80) {
    result = wrapper(divisor); // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
