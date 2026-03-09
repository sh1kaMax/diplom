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
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdlib.h>

int buffer[27];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 250;
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var = 0;

  index = 27;

  callee(&var, 3);

  if (var > 200) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}
