// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: linear-filtered-inverted.c
// Прямолинейный участок кода от источника до стока с фильтрацией после стока.

#include <stdlib.h>

void model_external_func(int external_param);

int *func(void) {

  int *x = malloc(sizeof(int));

  if (x != NULL) {
    model_external_func(*x); // FLAW
  }

  if (x != NULL) {
    *x = 94;
  }

  return x;
}
