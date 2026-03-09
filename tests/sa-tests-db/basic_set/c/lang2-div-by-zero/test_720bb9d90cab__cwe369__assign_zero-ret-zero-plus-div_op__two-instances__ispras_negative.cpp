// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 73; }

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int divident = 25, divisor = 6, result;

  SomeClass *cl_var1 = new SomeClass(30);
  SomeClass *cl_var2 = new SomeClass(-36);

  divisor = wrapper(34);
  divisor -= 73;

  if (cl_var2->getVal() > -27) {
    result = divident / divisor;
  }

  delete cl_var1;
  delete cl_var2;
}
