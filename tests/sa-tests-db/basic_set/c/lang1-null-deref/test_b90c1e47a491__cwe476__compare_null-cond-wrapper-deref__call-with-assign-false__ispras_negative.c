// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-cond-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр больше нуля.
//
// Поточный вариант: call-with-assign-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель. Присвоенное значение
// сравнивается с константой, проверка неуспешна и выполнение не достигает
// стока.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

void callee(int *pointer_param) { *pointer_param = 183; }

int func(int *param) {
  int template_flag = 0;

  int var = 0;
  int other = 16;

  if (param == NULL) {
    template_flag = 54;
  }

  callee(&var);

  if (var > other) {
    exit(0);
  }

  wrapper(param, 90);

  return 0;
}
