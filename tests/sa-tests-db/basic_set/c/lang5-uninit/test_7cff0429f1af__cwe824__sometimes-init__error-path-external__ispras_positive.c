// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: sometimes-init.json
//
// Запись значения по указателю, инициализированному не на всех путях.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

void func(int *input_ptr, int cond_param) {

  int *x;
  if (cond_param > 0) {
    x = input_ptr;
  }

  if (external_func())
    goto error_label;

  x = input_ptr;

  exit(0);

error_label:
  *x = -26; // FLAW
}
