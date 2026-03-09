// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

void model_external_func(int external_param);

int *func(void) {

  int flag = 0;

  int *x = malloc(sizeof(int));

  if (1)
    flag = 1;

  if (flag != 0)
    goto error_label;

  if (x != NULL) {
    *x = 39;
  }

  exit(0);

error_label:
  if (x != NULL) {
    model_external_func(*x); // FLAW
  }

  return x;
}
