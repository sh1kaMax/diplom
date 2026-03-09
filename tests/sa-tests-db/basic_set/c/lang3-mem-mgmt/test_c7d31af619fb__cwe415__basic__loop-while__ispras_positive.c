// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int var;

  pointer = (int *)malloc(19 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  var = 0;

  while (var < 17)
    var++;

  free(pointer); // FLAW
}
