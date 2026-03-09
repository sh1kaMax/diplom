// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-compare.json
//
// Чтение значения неинициализированной переменной для использования в условном
// операторе.
//
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int x;

  if (1) {
    x = -94;
  } else {
    if (x > 0) {
      result = 1;
    }
  }

  return result;
}
