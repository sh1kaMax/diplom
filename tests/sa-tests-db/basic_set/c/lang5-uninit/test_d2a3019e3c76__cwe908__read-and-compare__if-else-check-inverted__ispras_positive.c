// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

int *func(void) {

  int *x = malloc(sizeof(int));

  if (!(1)) {
    exit(0);
  } else {
    if (x != NULL && *x < 0) { // FLAW
      *x = 0;
    }
  }

  return x;
}
