// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-global-const_size-func-access-if.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, если 2й параметр
// функции больше нуля. Индекс является константой.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int buffer[39];
int get_buffer_elem(int elem_index, int temp_flag) {
  if (temp_flag > 0)
    return buffer[elem_index];
  return 0;
}

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 69; }

template <> unsigned int get_template<float>(float c) { return -4; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 69;

  if (local_var1 > 22) {
    index = 39;
  }

  if (get_template('a') > 22) {
    result = get_buffer_elem(index, 1); // FLAW
  }

  return;
}
