// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-tainted_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdio.h>
#include <stdlib.h>

int result = 0;

void func(void) {
  unsigned int size;
  scanf("%u", &size);
  int *buffer = (int *)malloc(size * sizeof(int));
  unsigned int index = 0;

  index = 37;

  index = size - 1;

  result = buffer[index];

  free(buffer);
  return;
}
