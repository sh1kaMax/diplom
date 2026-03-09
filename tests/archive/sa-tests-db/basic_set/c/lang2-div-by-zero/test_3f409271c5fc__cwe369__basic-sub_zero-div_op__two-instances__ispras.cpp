// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
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
  int divident = 50, divisor = 5, result;
  int var_a = 152;
  int var_b = 152;

  SomeClass *cl_var1 = new SomeClass(47);
  SomeClass *cl_var2 = new SomeClass(-4);

  divisor = var_a - var_b;

  if (cl_var2->getVal() > 2) {
    result = divident / divisor;
  }

  delete cl_var1;
  delete cl_var2;
}
