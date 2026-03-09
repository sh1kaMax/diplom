// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-arithm.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости.

#include <stdlib.h>

int *func(void) {

  int *x = malloc(sizeof(int));

  if (1) {
    if (x != NULL) {
      *x = 65;
    }
  } else {
    if (x != NULL) {
      *x += 1;
    }
  }

  return x;
}
