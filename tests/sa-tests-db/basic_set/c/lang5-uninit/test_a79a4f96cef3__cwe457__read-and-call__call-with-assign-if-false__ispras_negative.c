// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdlib.h>

int model_external_func(int external_param);

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 51;
}

int func(void) {
  int result = 0;

  int var = 0;

  int x;

  callee(&var, 8);

  if (var > 4) {
    exit(0);
  }

  result = model_external_func(x);

  return result;
}
