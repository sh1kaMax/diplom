// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: write.json
//
// Запись значения по неинициализированному указателю.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

void func(int *input_ptr) {

  int flag = 0;

  int *x;

  if (1)
    flag = 1;

  if (flag != 0) {

    x = input_ptr;

    goto error_label;
  }

  exit(0);

error_label:
  *x = 5;
}
