// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: local-array-const_size-func-access-with-check.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. В функции доступа есть проверка на границы индекса, но она
// недостаточная Индекс является константой. Нормально, если анализатор выдаст
// предупреждение только внутри функции get_buffer_elem, т.к. кода этой функции
// достаточно, чтобы сообщить о проблеме, нет смысла выдавать выше.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[38];
  int cur_index = 0;
  for (; cur_index < 38; cur_index++)
    buffer[cur_index] = 7;
  if (elem_index > 38)
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

  std::vector<int> vec(65, 0);

  int local_var1 = 50;
  int local_var2 = 143;
  int index1 = 24;
  int index2 = 26;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 38;
  }

  if (local_var1 == vec[24]) {
    result = get_buffer_elem(index); // FLAW
  }

  return;
}
