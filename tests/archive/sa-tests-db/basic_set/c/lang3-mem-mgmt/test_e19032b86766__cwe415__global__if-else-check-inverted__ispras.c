// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  pointer = (int *)malloc(18 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (!(freed_flag == 1)) {
    exit(0);
  } else {
    free(pointer); // FLAW
  }
}
