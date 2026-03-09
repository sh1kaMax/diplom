// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdlib.h>

void model_external_func(int external_param);

int *func(void) {

  int *x = malloc(sizeof(int));

  if (x != NULL) {
    *x = -38;
  }

  if (x != NULL) {
    model_external_func(*x);
  }

  return x;
}
