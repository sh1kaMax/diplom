// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-auto-tainted_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

void func(void) {
  unsigned int size;
  scanf("%u", &size);
  int buffer[size];
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 70;

  auto init = [&]() { local_var1 = 189; };

  if (local_var1 > 65) {
    index = 28;
  }

  init();

  if (local_var1 == 189) {
    memset(buffer, 0, index * sizeof(int)); // FLAW
    use_mem_to_keep_memset(buffer);
  }

  return;
}
