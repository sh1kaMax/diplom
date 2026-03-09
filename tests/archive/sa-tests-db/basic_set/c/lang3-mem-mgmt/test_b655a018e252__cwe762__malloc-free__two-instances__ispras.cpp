// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: malloc-free.json
//
// Память выделяется с помощью стандартной функции malloc.
// Память освобождается с помощью стандартной функции free.
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

  SomeClass *cl_var1 = new SomeClass(41);
  SomeClass *cl_var2 = new SomeClass(-60);

  pointer = (int *)malloc(28 * sizeof(int));

  if (cl_var1->getVal() > 39) {
    free(pointer);
  }

  delete cl_var1;
  delete cl_var2;
}
