// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
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

  SomeClass *cl_var1 = new SomeClass(84);
  SomeClass *cl_var2 = new SomeClass(-44);

  pointer = (int *)malloc(23 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (cl_var1->getVal() > 76) {
    free(pointer); // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
