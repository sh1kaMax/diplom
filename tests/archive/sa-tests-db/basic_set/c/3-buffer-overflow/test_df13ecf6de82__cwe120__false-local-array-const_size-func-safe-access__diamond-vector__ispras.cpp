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
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[34];
  int cur_index = 0;
  for (; cur_index < 34; cur_index++)
    buffer[cur_index] = 24;
  if (elem_index >= 34)
    return -1;
  return buffer[elem_index];
}

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int result = 0;
  unsigned int index = 0;

  std::vector<int> vec(10, 0);

  int local_var1 = 25;
  int local_var2 = 35;
  int index1 = 3;
  int index2 = 5;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 34;
  }

  if (local_var1 == vec[3]) {
    result = get_buffer_elem(index);
  }

  return;
}
