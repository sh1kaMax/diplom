// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-dynamic-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int result = 0;

void func(void) {
  int iter_var;

  int *buffer = (int *)malloc(23 * sizeof(int));
  unsigned int index = 0;

  for (iter_var = 5; iter_var < 11; iter_var++) {
    index = 23;

    result = buffer[index]; // FLAW
  }

  free(buffer);
  return;
}
