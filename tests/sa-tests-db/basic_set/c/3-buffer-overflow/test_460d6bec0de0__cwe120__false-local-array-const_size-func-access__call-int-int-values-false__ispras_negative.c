// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-local-array-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. Индекс является константой.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[30];
  int cur_index = 0;
  for (; cur_index < 30; cur_index++)
    buffer[cur_index] = 29;
  return buffer[elem_index];
}

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var = 3;

  index = 30;

  if (callee(local_var, 72) > 0) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}
