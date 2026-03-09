// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: sometimes-init.json
//
// Чтение значения переменной, инициализированной не на всех путях.
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

int func(int param, int cond_param) {
  int result = 0;

  int x;
  if (cond_param > 0) {
    x = cond_param;
  }

  if (param > 45 && param < 46) {
    result = x + 1;
  }

  return result;
}
