// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-return.json
//
// Возврат значения неинициализированного указателя из функции.
//
// Поточный вариант: switch-default-inverted.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int *func(void) {
  int *result = NULL;

  int var;

  int *x;

  var = 0;

  switch (var) {
  case 0:
    result = x; // FLAW
    break;
  default:
    exit(0);
    break;
  }

  return result;
}
