// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  int var;

  pointer = (int *)malloc(22 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  var = 0;

  for (var = 0; var < 18; var++)
    ;

  free(pointer); // FLAW
}
