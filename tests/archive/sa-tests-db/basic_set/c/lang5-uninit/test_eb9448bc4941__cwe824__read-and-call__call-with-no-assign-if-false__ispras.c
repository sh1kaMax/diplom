// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: call-with-no-assign-if-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

int model_external_func(int *external_param);

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 457;
}

int func(void) {
  int result = 0;

  int var = 0;

  int *x;

  callee(&var, -3);

  if (var < 534) {
    exit(0);
  }

  result = model_external_func(x);

  return result;
}
