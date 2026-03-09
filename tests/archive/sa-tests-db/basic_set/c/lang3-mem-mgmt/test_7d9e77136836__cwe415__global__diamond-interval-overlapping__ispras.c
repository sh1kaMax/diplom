// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

int *pointer = NULL;

void func(int param) {
  int freed_flag = 0;

  if (param > 12 && param < 43) {
    pointer = (int *)malloc(11 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (param > 38 && param < 43) {
    free(pointer); // FLAW
  }
}
