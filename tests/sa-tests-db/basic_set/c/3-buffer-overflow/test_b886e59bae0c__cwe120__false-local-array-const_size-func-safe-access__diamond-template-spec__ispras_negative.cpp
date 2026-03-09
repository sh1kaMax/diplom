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
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[28];
  int cur_index = 0;
  for (; cur_index < 28; cur_index++)
    buffer[cur_index] = 85;
  if (elem_index >= 28)
    return -1;
  return buffer[elem_index];
}

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 34; }

template <> unsigned int get_template<float>(float c) { return -78; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 34;

  if (local_var1 > -3) {
    index = 28;
  }

  if (get_template(0.33) > -3) {
    result = get_buffer_elem(index);
  }

  return;
}
