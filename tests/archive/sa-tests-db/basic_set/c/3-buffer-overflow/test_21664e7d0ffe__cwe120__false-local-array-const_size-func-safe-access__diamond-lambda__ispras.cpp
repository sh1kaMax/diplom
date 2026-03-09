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
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[29];
  int cur_index = 0;
  for (; cur_index < 29; cur_index++)
    buffer[cur_index] = 38;
  if (elem_index >= 29)
    return -1;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 46;

  auto init = [&]() { local_var1 = 174; };

  if (local_var1 > -1) {
    index = 29;
  }

  init();

  if (local_var1 == 174) {
    result = get_buffer_elem(index);
  }

  return;
}
