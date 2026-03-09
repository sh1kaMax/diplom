// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-with-no-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

int model_external_func(int external_param);

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 454;
}

int func(void) {
  int result = 0;

  int var = 0;

  int x;

  callee(&var, -10);

  if (var > 860) {
    exit(0);
  }

  result = model_external_func(x); // FLAW

  return result;
}
