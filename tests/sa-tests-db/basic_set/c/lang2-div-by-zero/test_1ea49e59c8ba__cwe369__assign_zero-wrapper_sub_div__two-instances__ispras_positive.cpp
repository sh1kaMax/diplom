// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1854 / (wrapper_par - 10); }

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int divident = 41, divisor = 9, result;

  SomeClass *cl_var1 = new SomeClass(34);
  SomeClass *cl_var2 = new SomeClass(-25);

  divisor = 10;

  if (cl_var1->getVal() > 32) {
    result = wrapper(divisor); // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
