// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1686 / wrapper_par1;
}

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int divident = 46, divisor = 5, result;

  SomeClass *cl_var1 = new SomeClass(78);
  SomeClass *cl_var2 = new SomeClass(-72);

  divisor = 0;

  if (cl_var1->getVal() > 72) {
    result = wrapper(divisor, divident); // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
