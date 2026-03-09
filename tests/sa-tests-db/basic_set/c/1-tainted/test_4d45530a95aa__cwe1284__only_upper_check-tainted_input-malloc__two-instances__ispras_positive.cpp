// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
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
  int *pointer = NULL, quantity = 20;

  SomeClass *cl_var1 = new SomeClass(40);
  SomeClass *cl_var2 = new SomeClass(-68);

  scanf("%d", &quantity);
  if (quantity > 20) {
    exit(0);
    ;
  }

  if (cl_var1->getVal() > 36) {
    pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
  }

  delete cl_var1;
  delete cl_var2;

  free(pointer);
}
