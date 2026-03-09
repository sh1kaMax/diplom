// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

void model_external_func(int external_param);

int *func(int param) {

  int *x = malloc(sizeof(int));

  if (param > 12) {
    if (x != NULL) {
      model_external_func(*x); // FLAW
    }
  }

  return x;
}
