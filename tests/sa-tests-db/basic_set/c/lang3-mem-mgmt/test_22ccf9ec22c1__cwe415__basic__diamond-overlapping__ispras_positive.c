// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: diamond-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  if (param > 8) {
    pointer = (int *)malloc(15 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (param < 25) {
    free(pointer); // FLAW
  }
}
