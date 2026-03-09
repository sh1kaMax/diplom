// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости.

#include <stdlib.h>

int *func(void) {

  int *x = malloc(sizeof(int));

  if (1) {
    if (x != NULL) {
      *x = 70;
    }
  } else {
    if (x != NULL && *x < 0) {
      *x = 0;
    }
  }

  return x;
}
