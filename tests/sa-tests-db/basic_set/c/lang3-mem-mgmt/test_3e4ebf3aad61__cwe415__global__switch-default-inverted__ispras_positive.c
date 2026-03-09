// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: switch-default-inverted.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  int var;

  pointer = (int *)malloc(26 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  var = 0;

  switch (var) {
  case 0:
    free(pointer); // FLAW
    break;
  default:
    exit(0);
    break;
  }
}
