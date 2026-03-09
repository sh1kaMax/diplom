// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: local-array-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. Индекс является константой.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[29];
  int cur_index = 0;
  for (; cur_index < 29; cur_index++)
    buffer[cur_index] = 18;
  return buffer[elem_index];
}

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 84; }

template <> unsigned int get_template<float>(float c) { return -52; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 84;

  if (local_var1 > 74) {
    index = 29;
  }

  if (get_template('a') > 74) {
    result = get_buffer_elem(index); // FLAW
  }

  return;
}
