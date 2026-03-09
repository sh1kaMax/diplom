// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

void model_external_func(int external_param);

int *func(void) {

  int var;

  int *x = malloc(sizeof(int));

  var = 0;

  do {
    var++;
  } while (var < 20);

  if (x != NULL) {
    model_external_func(*x); // FLAW
  }

  return x;
}
