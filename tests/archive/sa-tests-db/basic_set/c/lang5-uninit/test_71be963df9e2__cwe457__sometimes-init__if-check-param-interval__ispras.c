// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: sometimes-init.json
//
// Чтение значения переменной, инициализированной не на всех путях.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int func(int param, int cond_param) {
  int result = 0;

  int x;
  if (cond_param > 0) {
    x = cond_param;
  }

  if (param > 19 && param < 64) {
    result = x + 1; // FLAW
  }

  return result;
}
