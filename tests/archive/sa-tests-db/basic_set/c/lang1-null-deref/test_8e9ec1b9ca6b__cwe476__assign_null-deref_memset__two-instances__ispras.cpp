// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_memset.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  SomeClass *cl_var1 = new SomeClass(95);
  SomeClass *cl_var2 = new SomeClass(-36);

  pointer = NULL;

  if (cl_var2->getVal() > -32) {
    memset(pointer, 0, sizeof(int));
    use_mem_to_keep_memset(pointer);
  }

  delete cl_var1;
  delete cl_var2;
}
