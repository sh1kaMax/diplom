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
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *buffer = (int *)malloc(31 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  scanf("%u", &index);

  if (!(index >= 31)) {
    index = 31 - 1;
  }

  result = buffer[index]; // FLAW

  free(buffer);
  return;
}
