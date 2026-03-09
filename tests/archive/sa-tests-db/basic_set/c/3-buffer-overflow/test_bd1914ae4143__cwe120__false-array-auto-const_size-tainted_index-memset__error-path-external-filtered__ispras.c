// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-auto-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int external_func(void);

void use_mem_to_keep_memset(int *);

void func(void) {
  int buffer[21];
  int result = 0;
  unsigned int index = 0;

  scanf("%u", &index);

  if (external_func()) {

    index = 21;

    goto error_label;
  }

  exit(0);

error_label:
  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  return;
}
