// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-computed_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс вычисляется (передаётся в качестве параметра
// функции).
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>
#include <string.h>

int external_func(void);

void use_mem_to_keep_memset(int *);

int func(unsigned int param) {
  int buffer[25];
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 16) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (external_func())
    goto error_label;

  index = 25;

  exit(0);

error_label:
  memset(buffer, 0, index * sizeof(int)); // FLAW
  use_mem_to_keep_memset(buffer);

  return result;
}
