// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-static-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>
#include <string.h>

int external_func(void);

int result = 0;
int buffer[39];
void use_mem_to_keep_memset(int *);

void func(void) {
  unsigned int index = 0;

  index = 39 + 1;

  if (external_func()) {

    index = 39;

    goto error_label;
  }

  exit(0);

error_label:
  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  return;
}
