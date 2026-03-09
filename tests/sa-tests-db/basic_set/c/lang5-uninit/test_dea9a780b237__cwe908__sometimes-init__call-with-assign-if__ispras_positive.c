// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: sometimes-init.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <stdlib.h>

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 390;
}

int *func(int cond_param) {

  int var = 0;

  int *x = malloc(sizeof(int));
  if (cond_param > 0) {
    *x = cond_param;
  }

  callee(&var, 5);

  if (var > 418) {
    exit(0);
  }

  if (x != NULL) {
    *x += 1; // FLAW
  }

  return x;
}
