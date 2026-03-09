// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int func(unsigned int param) {
  int buffer[22];
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 13) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (external_func())
    goto error_label;

  index = 22 - 1;

  exit(0);

error_label:
  result = buffer[index]; // FLAW

  return result;
}
