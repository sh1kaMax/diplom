// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Память освобождается с помощью указателя, указывающего не на начало
// выделенного блока.
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
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  SomeClass *cl_var1 = new SomeClass(94);
  SomeClass *cl_var2 = new SomeClass(-19);

  pointer1 = (int *)malloc(11 * sizeof(int));
  pointer2 = pointer1 + 11;

  if (cl_var1->getVal() > 84) {
    free(pointer2); // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
