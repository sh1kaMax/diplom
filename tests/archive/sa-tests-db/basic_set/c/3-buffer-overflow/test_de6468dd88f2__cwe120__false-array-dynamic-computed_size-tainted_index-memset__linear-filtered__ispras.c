// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-array-dynamic-computed_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера вычисляется (передаётся в качестве параметра функции).
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int func(unsigned int param) {
  int *buffer = (int *)malloc(param * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  scanf("%u", &index);

  index = param;

  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  free(buffer);
  return result;
}
