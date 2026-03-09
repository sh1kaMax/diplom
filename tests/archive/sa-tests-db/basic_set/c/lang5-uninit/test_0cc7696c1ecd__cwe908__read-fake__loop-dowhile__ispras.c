// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-fake.json
//
// Отсутствие чтения значения из неинициализированной памяти, несмотря не ее
// использование при вычислении выражения.
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
  } while (var < 13);

  if (x != NULL) {
    *x = sizeof *x;
  }

  return x;
}
