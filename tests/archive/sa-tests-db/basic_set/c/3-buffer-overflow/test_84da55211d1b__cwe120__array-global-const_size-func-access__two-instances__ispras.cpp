// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int buffer[25];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int result = 0;
  unsigned int index = 0;

  SomeClass *cl_var1 = new SomeClass(55);
  SomeClass *cl_var2 = new SomeClass(-76);

  index = 25;

  if (cl_var1->getVal() > 48) {
    result = get_buffer_elem(index); // FLAW
  }

  delete cl_var1;
  delete cl_var2;

  return;
}
