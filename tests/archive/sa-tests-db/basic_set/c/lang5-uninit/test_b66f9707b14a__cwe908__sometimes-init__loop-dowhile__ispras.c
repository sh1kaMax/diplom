// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: sometimes-init.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int *func(int cond_param) {

  int var;

  int *x = malloc(sizeof(int));
  if (cond_param > 0) {
    *x = cond_param;
  }

  var = 0;

  do {
    var++;
  } while (var < 14);

  if (x != NULL) {
    *x += 1; // FLAW
  }

  return x;
}
