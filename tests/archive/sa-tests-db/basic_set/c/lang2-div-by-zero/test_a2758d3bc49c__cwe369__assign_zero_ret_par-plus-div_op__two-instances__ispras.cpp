// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int divident = 69, divisor = 8, result;

  SomeClass *cl_var1 = new SomeClass(72);
  SomeClass *cl_var2 = new SomeClass(-16);

  divisor = wrapper(31);
  divisor -= 31;

  if (cl_var1->getVal() > 70) {
    result = divident / divisor; // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
