// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: sometimes-init.json
//
// Чтение значения переменной, инициализированной не на всех путях.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

int func(int cond_param) {
  int result = 0;

  int x;
  if (cond_param > 0) {
    x = cond_param;
  }

  if (external_func()) {

    x = 47;

    goto error_label;
  }

  exit(0);

error_label:
  result = x + 1;

  return result;
}
