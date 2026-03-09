// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: sometimes-init.json
//
// Запись значения по указателю, инициализированному не на всех путях.
//
// Поточный вариант: switch-default-inverted.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

void func(int *input_ptr, int cond_param) {

  int var;

  int *x;
  if (cond_param > 0) {
    x = input_ptr;
  }

  var = 0;

  switch (var) {
  case 0:
    *x = 27; // FLAW
    break;
  default:
    exit(0);
    break;
  }
}
