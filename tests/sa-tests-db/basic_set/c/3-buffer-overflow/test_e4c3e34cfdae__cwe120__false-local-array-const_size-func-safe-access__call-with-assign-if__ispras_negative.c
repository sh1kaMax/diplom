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
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[20];
  int cur_index = 0;
  for (; cur_index < 20; cur_index++)
    buffer[cur_index] = 45;
  if (elem_index >= 20)
    return -1;
  return buffer[elem_index];
}

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 358;
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var = 0;

  index = 20;

  callee(&var, 6);

  if (var > 978) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}
