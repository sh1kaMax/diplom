// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// basic-array-dynamic-const_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *buffer = (int *)malloc(20 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 66;

  auto init = [&]() { local_var1 = 185; };

  if (local_var1 > 38) {
    scanf("%u", &index);
  }

  init();

  if (local_var1 == 185) {
    result = buffer[index]; // FLAW
  }

  free(buffer);
  return;
}
