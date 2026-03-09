// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-static-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffer[26];
void use_mem_to_keep_memset(int *);

void func(void) {
  int result = 0;
  unsigned int index = 0;

  scanf("%u", &index);

  index = 26;

  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  return;
}
