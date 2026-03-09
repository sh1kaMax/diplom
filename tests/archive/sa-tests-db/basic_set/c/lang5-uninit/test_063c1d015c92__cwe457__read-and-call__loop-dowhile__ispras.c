// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int model_external_func(int external_param);

int func(void) {
  int result = 0;

  int var;

  int x;

  var = 0;

  do {
    var++;
  } while (var < 19);

  result = model_external_func(x); // FLAW

  return result;
}
