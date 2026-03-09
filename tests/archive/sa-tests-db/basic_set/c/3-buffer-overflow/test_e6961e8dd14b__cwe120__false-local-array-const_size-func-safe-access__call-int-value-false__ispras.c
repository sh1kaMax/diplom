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
// Поточный вариант: call-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[20];
  int cur_index = 0;
  for (; cur_index < 20; cur_index++)
    buffer[cur_index] = 44;
  if (elem_index >= 20)
    return -1;
  return buffer[elem_index];
}

int callee(int par1) {
  if (par1 > 34)
    return 20;

  return 10;
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var = 4;

  index = 20;

  if (callee(local_var) == 10) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}
