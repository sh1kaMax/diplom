// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: sometimes-init.json
//
// Запись значения по указателю, инициализированному не на всех путях.
//
// Поточный вариант: if-check.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, выход в случае истинности проверки.

#include <stdlib.h>

void func(int *input_ptr, int cond_param) {

  int *x;
  if (cond_param > 0) {
    x = input_ptr;
  }

  if (1) {
    exit(0);
  }

  *x = -85;
}
