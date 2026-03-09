// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-static-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffer[25];
void use_mem_to_keep_memset(int *);

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 47;

  auto init = [&]() { local_var1 = 171; };

  if (local_var1 > 39) {
    scanf("%u", &index);
  }

  init();

  if (local_var1 == 171) {
    memset(buffer, 0, index * sizeof(int)); // FLAW
    use_mem_to_keep_memset(buffer);
  }

  return;
}
