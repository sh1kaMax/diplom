// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: false-assign_null-cond-inverted-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр меньше или равен нулю. В
// функцию передаётся положительное значение, поэтому ошибки не будет.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par <= 0)
    *ptr = 1;
}

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  SomeClass *cl_var1 = new SomeClass(42);
  SomeClass *cl_var2 = new SomeClass(-55);

  pointer = NULL;

  if (cl_var1->getVal() > 32) {
    wrapper(pointer, 11);
  }

  delete cl_var1;
  delete cl_var2;
}
