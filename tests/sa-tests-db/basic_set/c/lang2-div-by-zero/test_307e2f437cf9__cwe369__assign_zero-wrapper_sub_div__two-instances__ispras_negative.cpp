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

int wrapper(int wrapper_par) { return 1613 / (wrapper_par - 16); }

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int divident = 57, divisor = 6, result;

  SomeClass *cl_var1 = new SomeClass(22);
  SomeClass *cl_var2 = new SomeClass(-22);

  divisor = 16;

  if (cl_var2->getVal() > -20) {
    result = wrapper(divisor);
  }

  delete cl_var1;
  delete cl_var2;
}
