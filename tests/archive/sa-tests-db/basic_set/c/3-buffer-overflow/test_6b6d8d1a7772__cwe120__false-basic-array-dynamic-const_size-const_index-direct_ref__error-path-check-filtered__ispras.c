// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

int result = 0;

void func(void) {
  int *buffer = (int *)malloc(22 * sizeof(int));
  unsigned int index = 0;

  index = 22;

  if (index >= 22) {

    index = 22 - 1;

    goto error_label;
  }

  exit(0);

error_label:
  result = buffer[index];

  free(buffer);
  return;
}
