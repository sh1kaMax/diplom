// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
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
  int divident = 19, divisor = 6, result;

  SomeClass *cl_var1 = new SomeClass(10);
  SomeClass *cl_var2 = new SomeClass(-80);

  divisor = 0;

  if (cl_var1->getVal() > 5) {
    result = divident % divisor; // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
