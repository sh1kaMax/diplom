// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: false-assign_null-cond-inverted-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр меньше или равен нулю. В
// функцию передаётся положительное значение, поэтому ошибки не будет.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par <= 0)
    *ptr = 1;
}

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int flag = 0;

  pointer = NULL;

  if (pointer == NULL)
    flag = 1;

  if (flag != 0) {

    pointer = &other;

    goto error_label;
  }

  exit(0);

error_label:
  wrapper(pointer, 19);
}
