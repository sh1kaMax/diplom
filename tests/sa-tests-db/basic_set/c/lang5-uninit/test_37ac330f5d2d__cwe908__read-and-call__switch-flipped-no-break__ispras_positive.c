// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

void model_external_func(int external_param);

int *func(void) {

  int var;

  int *x = malloc(sizeof(int));

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    if (x != NULL) {
      model_external_func(*x); // FLAW
    }
    break;
  }

  return x;
}
