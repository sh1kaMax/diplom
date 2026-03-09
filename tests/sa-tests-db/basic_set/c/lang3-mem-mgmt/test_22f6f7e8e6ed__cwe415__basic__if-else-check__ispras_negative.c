// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: if-else-check.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// устовием которого является условие наличия уязвимости.

#include <stdlib.h>

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  pointer = (int *)malloc(10 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (freed_flag == 1) {
    exit(0);
  } else {
    free(pointer);
  }
}
