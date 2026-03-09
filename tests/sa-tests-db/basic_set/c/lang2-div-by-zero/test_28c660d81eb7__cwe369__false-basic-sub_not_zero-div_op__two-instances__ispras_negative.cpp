// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int divident = 42, divisor = 9, result;
  int var_a = 36;
  int var_b = 43;

  SomeClass *cl_var1 = new SomeClass(2);
  SomeClass *cl_var2 = new SomeClass(-71);

  divisor = var_a - var_b;

  if (cl_var2->getVal() > -67) {
    result = divident / divisor;
  }

  delete cl_var1;
  delete cl_var2;
}
