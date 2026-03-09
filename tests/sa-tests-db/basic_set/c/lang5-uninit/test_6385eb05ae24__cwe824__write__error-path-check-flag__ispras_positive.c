// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: write.json
//
// Запись значения по неинициализированному указателю.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

void func(int *input_ptr) {

  int flag = 0;

  int *x;

  if (1)
    flag = 1;

  if (flag != 0)
    goto error_label;

  x = input_ptr;

  exit(0);

error_label:
  *x = 87; // FLAW
}
