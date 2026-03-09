// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-compare.json
//
// Чтение значения неинициализированной переменной для использования в условном
// операторе.
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

int func(void) {
  int result = 0;

  int x;

  if (!(1)) {
    exit(0);
  } else {
    if (x > 0) { // FLAW
      result = 1;
    }
  }

  return result;
}
