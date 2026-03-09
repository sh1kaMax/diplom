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
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <stdlib.h>
#include <string.h>

int result = 0;
int buffer[21];
void use_mem_to_keep_memset(int *);

void func(void) {
  unsigned int index = 0;

  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  index = 21 + 1;

  return;
}
