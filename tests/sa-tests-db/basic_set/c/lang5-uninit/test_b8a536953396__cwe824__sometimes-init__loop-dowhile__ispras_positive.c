// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: sometimes-init.json
//
// Запись значения по указателю, инициализированному не на всех путях.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

void func(int *input_ptr, int cond_param) {

  int var;

  int *x;
  if (cond_param > 0) {
    x = input_ptr;
  }

  var = 0;

  do {
    var++;
  } while (var < 20);

  *x = -2; // FLAW
}
