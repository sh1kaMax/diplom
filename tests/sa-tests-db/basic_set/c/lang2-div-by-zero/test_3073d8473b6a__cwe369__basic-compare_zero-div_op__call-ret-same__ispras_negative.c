// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-div_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-ret-same.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая просто возвращает свой аргумент. Поэтому проверка в
// вызывающей функции успешна и выполнение не достигает стока

#include <stdlib.h>

int callee(int par1) { return par1; }

int func(int param) {
  int divident = 25, result;

  int local_res = callee(param);

  if (param == 0) {
    divident = 33;
  }

  if (local_res == param) {
    exit(0);
  }

  result = divident / param;

  return result;
}
