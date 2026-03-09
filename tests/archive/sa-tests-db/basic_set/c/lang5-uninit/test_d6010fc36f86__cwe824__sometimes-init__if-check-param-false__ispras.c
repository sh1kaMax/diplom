// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: sometimes-init.json
//
// Запись значения по указателю, инициализированному не на всех путях.
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

void func(int param, int *input_ptr, int cond_param) {

  int *x;
  if (cond_param > 0) {
    x = input_ptr;
  }

  if (param > 43 && param < 44) {
    *x = -78;
  }
}
