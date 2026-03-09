// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: sometimes-init.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int *func(int cond_param) {

  int flag = 0;

  int *x = malloc(sizeof(int));
  if (cond_param > 0) {
    *x = cond_param;
  }

  if (1)
    flag = 1;

  if (flag != 0)
    goto error_label;

  if (x != NULL) {
    *x = -59;
  }

  exit(0);

error_label:
  if (x != NULL) {
    *x += 1; // FLAW
  }

  return x;
}
