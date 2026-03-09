// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int buffer[23];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 75; }

template <> unsigned int get_template<float>(float c) { return -9; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 75;

  if (local_var1 > 44) {
    index = 23;
  }

  if (get_template(0.33) > 44) {
    result = get_buffer_elem(index);
  }

  return;
}
