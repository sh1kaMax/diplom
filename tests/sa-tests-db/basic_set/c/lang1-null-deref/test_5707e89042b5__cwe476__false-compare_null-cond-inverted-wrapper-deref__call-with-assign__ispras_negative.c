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
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

void callee(int *pointer_param) { *pointer_param = 164; }

int func(int *param) {
  int template_flag = 0;

  int var = 0;
  int other = 67;

  if (param == NULL) {
    template_flag = 57;
  }

  callee(&var);

  if (var < other) {
    exit(0);
  }

  wrapper(param, -5);

  return 0;
}
