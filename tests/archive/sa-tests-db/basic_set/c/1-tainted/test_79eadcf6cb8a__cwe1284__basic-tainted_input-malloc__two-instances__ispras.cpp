// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdio.h>
#include <stdlib.h>

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int *pointer = NULL, quantity = 11;

  SomeClass *cl_var1 = new SomeClass(89);
  SomeClass *cl_var2 = new SomeClass(-1);

  scanf("%d", &quantity);

  if (cl_var2->getVal() > 9) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  delete cl_var1;
  delete cl_var2;

  free(pointer);
}
