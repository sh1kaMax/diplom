// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: diamond-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int *pointer = NULL;

void func(int param) {
  int freed_flag = 0;

  if (param > 19) {
    pointer = (int *)malloc(14 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (param < 28) {
    free(pointer); // FLAW
  }
}
