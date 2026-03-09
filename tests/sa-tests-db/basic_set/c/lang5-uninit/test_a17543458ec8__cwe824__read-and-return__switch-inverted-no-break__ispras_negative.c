// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-return.json
//
// Возврат значения неинициализированного указателя из функции.
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока.

#include <stdlib.h>

int *func(void) {
  int *result = NULL;

  int var;

  int *x;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    result = x;
    break;
  }

  return result;
}
