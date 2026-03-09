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
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *buffer = (int *)malloc(20 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  scanf("%u", &index);

  if (index >= 20)
    goto error_label;

  index = 20 - 1;

  exit(0);

error_label:
  result = buffer[index]; // FLAW

  free(buffer);
  return;
}
