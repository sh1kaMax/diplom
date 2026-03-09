// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-local-array-const_size-func-safe-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. В функции доступа есть проверка на границы индекса. Индекс
// является константой.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[26];
  int cur_index = 0;
  for (; cur_index < 26; cur_index++)
    buffer[cur_index] = 31;
  if (elem_index >= 26)
    return -1;
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

  SomeClass *cl_var1 = new SomeClass(61);
  SomeClass *cl_var2 = new SomeClass(-31);

  index = 26;

  if (cl_var1->getVal() > 60) {
    result = get_buffer_elem(index);
  }

  delete cl_var1;
  delete cl_var2;

  return;
}
