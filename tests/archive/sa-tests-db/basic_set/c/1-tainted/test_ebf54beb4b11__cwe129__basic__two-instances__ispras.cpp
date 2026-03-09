// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdio.h>
#include <stdlib.h>

int store;

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  SomeClass *cl_var1 = new SomeClass(43);
  SomeClass *cl_var2 = new SomeClass(-47);

  scanf("%d", &index);

  if (cl_var1->getVal() > 35) {
    store = array[index]; // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
