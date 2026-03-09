// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-local-array-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. Индекс является константой.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[24];
  int cur_index = 0;
  for (; cur_index < 24; cur_index++)
    buffer[cur_index] = 11;
  return buffer[elem_index];
}

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int result = 0;
  unsigned int index = 0;

  SomeClass *cl_var1 = new SomeClass(35);
  SomeClass *cl_var2 = new SomeClass(-62);

  index = 24;

  if (cl_var2->getVal() > -56) {
    result = get_buffer_elem(index);
  }

  delete cl_var1;
  delete cl_var2;

  return;
}
