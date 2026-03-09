// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdlib.h>

void model_external_func(int external_param);

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 226;
}

int *func(void) {

  int var = 0;

  int *x = malloc(sizeof(int));

  callee(&var, 9);

  if (var > 114) {
    exit(0);
  }

  if (x != NULL) {
    model_external_func(*x);
  }

  return x;
}
