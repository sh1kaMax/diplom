// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-arithm.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int *func(void) {

  int var;

  int *x = malloc(sizeof(int));

  var = 0;

  do {
    var++;
  } while (var < 15);

  if (x != NULL) {
    *x += 1; // FLAW
  }

  return x;
}
