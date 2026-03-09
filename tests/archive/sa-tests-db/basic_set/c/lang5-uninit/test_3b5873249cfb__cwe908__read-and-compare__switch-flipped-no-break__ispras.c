// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int *func(void) {

  int var;

  int *x = malloc(sizeof(int));

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    if (x != NULL && *x < 0) { // FLAW
      *x = 0;
    }
    break;
  }

  return x;
}
