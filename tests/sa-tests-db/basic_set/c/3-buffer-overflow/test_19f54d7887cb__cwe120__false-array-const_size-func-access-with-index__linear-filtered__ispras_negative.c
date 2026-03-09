// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-const_size-func-access-with-index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которую передаётся
// массив по указателю. Индекс является константой.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdlib.h>

int get_buffer_elem(int *buf_ptr_par, int buf_index_par) {
  return buf_ptr_par[buf_index_par];
}

void func(void) {
  int buffer[39];
  int result = 0;
  unsigned int index = 0;

  index = 39;

  index = index / 2;

  result = get_buffer_elem(buffer, index);

  return;
}
