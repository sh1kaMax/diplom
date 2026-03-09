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
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[40];
  int cur_index = 0;
  for (; cur_index < 40; cur_index++)
    buffer[cur_index] = 27;
  return buffer[elem_index];
}

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int result = 0;
  unsigned int index = 0;

  std::vector<int> vec(64, 0);

  int local_var1 = 60;
  int local_var2 = 108;
  int index1 = 36;
  int index2 = 48;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 40;
  }

  if (local_var1 == vec[48]) {
    result = get_buffer_elem(index);
  }

  return;
}
