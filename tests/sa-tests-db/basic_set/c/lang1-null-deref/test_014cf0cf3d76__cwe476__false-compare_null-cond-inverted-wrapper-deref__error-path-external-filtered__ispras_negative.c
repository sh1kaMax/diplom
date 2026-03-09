// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: false-compare_null-cond-inverted-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр больше нуля. В функцию
// передаётся отрицательное значение, поэтому ошибки не будет.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

int func(int *param) {
  int template_flag = 0;

  if (param == NULL) {
    template_flag = 89;
  }

  if (external_func()) {

    param = &template_flag;

    goto error_label;
  }

  exit(0);

error_label:
  wrapper(param, -2);

  return 0;
}
