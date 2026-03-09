// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
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
  float divident = 31.92, divisor = 40.45, result;

  SomeClass *cl_var1 = new SomeClass(21);
  SomeClass *cl_var2 = new SomeClass(-14);

  divisor = 0.0;

  if (cl_var2->getVal() > -8) {
    result = divident / divisor;
  }

  delete cl_var1;
  delete cl_var2;
}
