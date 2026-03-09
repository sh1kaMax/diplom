// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  int var;

  pointer = (int *)malloc(12 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  case 1:
    free(pointer);
    break;
  }
}
