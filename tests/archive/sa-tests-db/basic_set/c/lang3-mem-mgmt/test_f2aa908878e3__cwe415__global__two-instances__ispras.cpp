// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int *pointer = NULL;

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int freed_flag = 0;

  SomeClass *cl_var1 = new SomeClass(77);
  SomeClass *cl_var2 = new SomeClass(-73);

  pointer = (int *)malloc(16 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (cl_var1->getVal() > 75) {
    free(pointer); // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
