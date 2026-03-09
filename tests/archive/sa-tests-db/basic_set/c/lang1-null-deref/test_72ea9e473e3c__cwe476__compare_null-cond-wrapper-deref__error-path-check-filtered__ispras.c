// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-cond-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр больше нуля.
//
// Поточный вариант: error-path-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация и переход по метке в случае истинности проверки.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

int func(int *param) {
  int template_flag = 0;

  if (param == NULL) {
    template_flag = 19;
  }

  if (template_flag > 0) {

    param = &template_flag;

    goto error_label;
  }

  exit(0);

error_label:
  wrapper(param, 9);

  return 0;
}
