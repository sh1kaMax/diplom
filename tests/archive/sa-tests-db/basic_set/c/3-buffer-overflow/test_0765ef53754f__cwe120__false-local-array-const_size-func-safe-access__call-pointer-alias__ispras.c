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
// Поточный вариант: call-pointer-alias.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой сначала сохраняется в локальную
// переменную-указатель, а затем с его помощью передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение нулевое,
// поэтому проверка в вызывающей функции неуспешна и выполнение достигает стока.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[31];
  int cur_index = 0;
  for (; cur_index < 31; cur_index++)
    buffer[cur_index] = 59;
  if (elem_index >= 31)
    return -1;
  return buffer[elem_index];
}

int callee(int *pointer_param) {
  if (*pointer_param > 0)
    return 1;
  else
    return 0;
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var = 0, *local_pointer = &local_var;

  index = 31;

  if (callee(local_pointer)) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}
