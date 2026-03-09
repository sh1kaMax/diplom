// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-arithm.json
//
// Чтение значения из неинициализированной памяти для использования при
// вычислении выражения.
//
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int *func(void) {

  int var;

  int *x = malloc(sizeof(int));

  var = 0;

  switch (var) {
  case 0:
    if (x != NULL) {
      *x += 1; // FLAW
    }
    break;
  case 1:
    exit(0);
  }

  return x;
}
