// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: sometimes-init.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

int *func(int cond_param) {

  int var;

  int *x = malloc(sizeof(int));
  if (cond_param > 0) {
    *x = cond_param;
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  case 1:
    if (x != NULL) {
      *x += 1;
    }
    break;
  }

  return x;
}
