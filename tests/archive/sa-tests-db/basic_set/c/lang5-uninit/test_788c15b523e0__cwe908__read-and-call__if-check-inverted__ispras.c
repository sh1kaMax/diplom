// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: if-check-inverted.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, выход в случае ложности проверки.

#include <stdlib.h>

void model_external_func(int external_param);

int *func(void) {

  int *x = malloc(sizeof(int));

  if (!(1)) {
    exit(0);
  }

  if (x != NULL) {
    model_external_func(*x); // FLAW
  }

  return x;
}
