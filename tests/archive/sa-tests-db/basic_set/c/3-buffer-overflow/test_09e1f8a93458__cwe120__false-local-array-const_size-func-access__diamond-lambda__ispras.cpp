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
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[32];
  int cur_index = 0;
  for (; cur_index < 32; cur_index++)
    buffer[cur_index] = 28;
  return buffer[elem_index];
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 18;

  auto init = [&]() { local_var1 = 129; };

  if (local_var1 < 129) {
    index = 32;
  }

  init();

  if (local_var1 < 129) {
    result = get_buffer_elem(index);
  }

  return;
}
