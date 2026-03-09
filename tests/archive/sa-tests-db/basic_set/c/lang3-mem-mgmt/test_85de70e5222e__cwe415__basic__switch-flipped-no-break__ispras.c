// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int var;

  pointer = (int *)malloc(22 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    free(pointer); // FLAW
    break;
  }
}
