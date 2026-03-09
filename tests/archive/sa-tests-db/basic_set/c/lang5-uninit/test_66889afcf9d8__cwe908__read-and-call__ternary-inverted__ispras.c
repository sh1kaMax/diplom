// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdlib.h>

void model_external_func(int external_param);

int *func(void) {

  int var;

  int *x = malloc(sizeof(int));

  var = (1 ? 0 : 1);

  if (var) {
    if (x != NULL) {
      model_external_func(*x);
    }
  }

  return x;
}
