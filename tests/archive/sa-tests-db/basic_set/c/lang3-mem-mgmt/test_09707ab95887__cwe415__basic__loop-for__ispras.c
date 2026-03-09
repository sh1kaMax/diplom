// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int var;

  pointer = (int *)malloc(18 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  var = 0;

  for (var = 0; var < 15; var++)
    ;

  free(pointer); // FLAW
}
