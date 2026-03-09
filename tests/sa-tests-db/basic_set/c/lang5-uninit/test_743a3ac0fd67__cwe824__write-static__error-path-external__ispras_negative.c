// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: write-static.json
//
// Запись значения по неинициализированному статическому указателю.
// Запись не производится, так как значение неинициализированного глобального
// указателя равно нулю.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

void func(int *input_ptr) {

  static int *x;

  if (external_func())
    goto error_label;

  x = input_ptr;

  exit(0);

error_label:
  if (x != NULL) {
    *x = 5;
  }
}
