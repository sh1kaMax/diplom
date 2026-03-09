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
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int get_buffer_elem(int *buf_ptr_par, int buf_index_par) {
  return buf_ptr_par[buf_index_par];
}

void func(void) {
  int buffer[19];
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 46;

  auto init = [&]() { local_var1 = 154; };

  if (local_var1 < 154) {
    index = 19;
  }

  init();

  if (local_var1 < 154) {
    result = get_buffer_elem(buffer, index);
  }

  return;
}
