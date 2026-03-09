// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: malloc-delete.json
//
// Память выделяется с помощью стандартной функции malloc.
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

  SomeClass *cl_var1 = new SomeClass(37);
  SomeClass *cl_var2 = new SomeClass(-1);

  pointer = (int *)malloc(21 * sizeof(int));

  if (cl_var1->getVal() > 28) {
    delete pointer; // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
