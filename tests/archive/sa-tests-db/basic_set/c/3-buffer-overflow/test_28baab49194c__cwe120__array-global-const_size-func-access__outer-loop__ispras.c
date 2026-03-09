// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int buffer[31];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

void func(void) {
  int iter_var;

  int result = 0;
  unsigned int index = 0;

  for (iter_var = 0; iter_var < 22; iter_var++) {
    index = 31;

    result = get_buffer_elem(index); // FLAW
  }

  return;
}
