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
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

int func(int *param) {
  int template_flag = 0;

  if (param == NULL) {
    template_flag = 9;
  }

  if (!(template_flag > 0)) {
    param = &template_flag;
  }

  wrapper(param, -6);

  return 0;
}
