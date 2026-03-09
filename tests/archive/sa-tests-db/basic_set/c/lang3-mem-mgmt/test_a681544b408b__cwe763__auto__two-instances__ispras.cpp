// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: auto.json
//
// Память выделяется в автоматической памяти (на стеке).
// Адрес выделенной памяти сохраняется в локальной переменной.
// Память освобождается с помощью указателя, не указывающего на кучу.
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
  int array[12];
  int *pointer = NULL;

  SomeClass *cl_var1 = new SomeClass(4);
  SomeClass *cl_var2 = new SomeClass(-48);

  pointer = array;

  if (cl_var2->getVal() > -39) {
    free(pointer);
  }

  delete cl_var1;
  delete cl_var2;
}
