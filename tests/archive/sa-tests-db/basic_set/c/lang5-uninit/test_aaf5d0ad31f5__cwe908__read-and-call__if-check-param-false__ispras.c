// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

void model_external_func(int external_param);

int *func(int param) {

  int *x = malloc(sizeof(int));

  if (param > 5 && param < 6) {
    if (x != NULL) {
      model_external_func(*x);
    }
  }

  return x;
}
