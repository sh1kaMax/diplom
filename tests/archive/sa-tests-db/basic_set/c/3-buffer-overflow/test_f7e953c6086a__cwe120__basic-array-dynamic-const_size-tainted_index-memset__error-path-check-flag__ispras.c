// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-dynamic-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

void func(void) {
  int *buffer = (int *)malloc(30 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  int flag = 0;

  scanf("%u", &index);

  if (index > 30)
    flag = 1;

  if (flag != 0)
    goto error_label;

  index = 30;

  exit(0);

error_label:
  memset(buffer, 0, index * sizeof(int)); // FLAW
  use_mem_to_keep_memset(buffer);

  free(buffer);
  return;
}
