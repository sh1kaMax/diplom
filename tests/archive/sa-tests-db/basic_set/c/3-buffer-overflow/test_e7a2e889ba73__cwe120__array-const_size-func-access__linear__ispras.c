// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которую передаётся
// массив по указателю. Индекс является константой.
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdlib.h>

int get_buffer_elem(int *buf_ptr_par) {
  int local_access_var = 35;
  return buf_ptr_par[local_access_var];
}

void func(void) {
  int buffer[34];
  int result = 0;
  unsigned int index = 0;

  index = 34;

  result = get_buffer_elem(buffer); // FLAW

  return;
}
