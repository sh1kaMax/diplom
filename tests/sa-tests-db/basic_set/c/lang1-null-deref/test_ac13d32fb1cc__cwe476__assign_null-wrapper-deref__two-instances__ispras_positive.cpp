// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  SomeClass *cl_var1 = new SomeClass(100);
  SomeClass *cl_var2 = new SomeClass(-79);

  pointer = NULL;

  if (cl_var1->getVal() > 98) {
    wrapper(pointer); // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
