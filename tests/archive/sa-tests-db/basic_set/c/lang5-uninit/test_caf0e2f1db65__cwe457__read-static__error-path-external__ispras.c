// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-static.json
//
// Чтение значения неинициализированной статической переменной для использования
// при вычислении выражения.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int func(void) {
  int result = 0;

  static int x;

  if (external_func())
    goto error_label;

  x = -18;

  exit(0);

error_label:
  result = x + 1;

  return result;
}
