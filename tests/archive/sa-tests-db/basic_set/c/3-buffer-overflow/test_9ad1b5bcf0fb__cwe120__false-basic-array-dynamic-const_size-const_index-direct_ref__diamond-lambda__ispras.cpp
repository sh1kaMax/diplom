// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

int result = 0;

void func(void) {
  int *buffer = (int *)malloc(34 * sizeof(int));
  unsigned int index = 0;

  int local_var1 = 100;

  auto init = [&]() { local_var1 = 246; };

  if (local_var1 < 246) {
    index = 34;
  }

  init();

  if (local_var1 < 246) {
    result = buffer[index];
  }

  free(buffer);
  return;
}
