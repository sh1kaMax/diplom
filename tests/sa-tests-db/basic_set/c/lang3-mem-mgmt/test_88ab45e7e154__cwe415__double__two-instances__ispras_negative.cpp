// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
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
  int freed_flag = 0;

  SomeClass *cl_var1 = new SomeClass(48);
  SomeClass *cl_var2 = new SomeClass(-73);

  pointer1 = (int *)malloc(18 * sizeof(int));
  pointer2 = (int *)malloc(18 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  if (cl_var2->getVal() > -64) {
    free(pointer1);
    free(pointer2);
    pointer1 = NULL;
  }

  delete cl_var1;
  delete cl_var2;

  free(pointer1);
}
