// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdio.h>
#include <stdlib.h>

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int divident = 20, divisor = 10, result;

  SomeClass *cl_var1 = new SomeClass(45);
  SomeClass *cl_var2 = new SomeClass(-61);

  scanf("%d", &divisor);

  if (cl_var1->getVal() > 36) {
    result = divident / divisor; // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
