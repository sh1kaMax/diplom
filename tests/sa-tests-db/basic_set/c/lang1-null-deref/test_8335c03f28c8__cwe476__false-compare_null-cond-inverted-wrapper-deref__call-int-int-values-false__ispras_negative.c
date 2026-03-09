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
// Поточный вариант: call-int-int-values-false.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение не
// достигает стока

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

int func(int *param) {
  int template_flag = 0;

  int other = 25;

  if (param == NULL) {
    template_flag = 54;
  }

  if (callee(other, 290) < 0) {
    exit(0);
  }

  wrapper(param, -10);

  return 0;
}
