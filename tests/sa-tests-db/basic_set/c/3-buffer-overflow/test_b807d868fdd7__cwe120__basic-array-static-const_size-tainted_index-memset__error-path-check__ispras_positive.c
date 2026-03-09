// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-static-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffer[31];
void use_mem_to_keep_memset(int *);

void func(void) {
  int result = 0;
  unsigned int index = 0;

  scanf("%u", &index);

  if (index > 31)
    goto error_label;

  index = 31;

  exit(0);

error_label:
  memset(buffer, 0, index * sizeof(int)); // FLAW
  use_mem_to_keep_memset(buffer);

  return;
}
