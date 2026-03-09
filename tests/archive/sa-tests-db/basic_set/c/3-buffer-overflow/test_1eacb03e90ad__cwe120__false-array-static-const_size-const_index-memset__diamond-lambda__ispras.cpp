// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-static-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>
#include <string.h>

int result = 0;
int buffer[39];
void use_mem_to_keep_memset(int *);

void func(void) {
  unsigned int index = 0;

  int local_var1 = 80;

  auto init = [&]() { local_var1 = 192; };

  if (local_var1 < 192) {
    index = 39 + 1;
  }

  init();

  if (local_var1 < 192) {
    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
  }

  return;
}
