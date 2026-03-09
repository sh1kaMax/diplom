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
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *buffer = (int *)malloc(35 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  index = 35 - 1;

  scanf("%u", &index);

  result = buffer[index]; // FLAW

  free(buffer);
  return;
}
