// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: array-new-delete.json
//
// Память выделяется с помощью оператора new[]
// Память освобождается с помощью оператора delete.
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
  int *pointer = NULL;
  int freed_flag = 0;

  SomeClass *cl_var1 = new SomeClass(19);
  SomeClass *cl_var2 = new SomeClass(-82);

  pointer = new int[30];

  if (cl_var1->getVal() > 15) {
    delete pointer; // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
