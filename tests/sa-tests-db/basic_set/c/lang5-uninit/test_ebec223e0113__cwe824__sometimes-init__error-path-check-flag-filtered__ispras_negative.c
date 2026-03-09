// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: sometimes-init.json
//
// Запись значения по указателю, инициализированному не на всех путях.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

void func(int *input_ptr, int cond_param) {

  int flag = 0;

  int *x;
  if (cond_param > 0) {
    x = input_ptr;
  }

  if (1)
    flag = 1;

  if (flag != 0) {

    x = input_ptr;

    goto error_label;
  }

  exit(0);

error_label:
  *x = -65;
}
