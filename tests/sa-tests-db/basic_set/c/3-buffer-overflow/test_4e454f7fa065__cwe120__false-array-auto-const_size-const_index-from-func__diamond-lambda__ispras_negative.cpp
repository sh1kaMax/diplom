// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 1; }

void func(void) {
  int buffer[28];
  unsigned int index = 0;

  int local_var1 = 58;

  auto init = [&]() { local_var1 = 194; };

  if (local_var1 < 194) {
    index = 28;
  }

  init();

  if (local_var1 < 194) {
    index = index_change_func(index);
    result = buffer[index];
  }

  return;
}
