// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-arithm.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int *func(void) {

  int var;

  int *x = malloc(sizeof(int));

  var = 0;

  for (var = 0; var < 10; var++)
    ;

  if (x != NULL) {
    *x += 1; // FLAW
  }

  return x;
}
