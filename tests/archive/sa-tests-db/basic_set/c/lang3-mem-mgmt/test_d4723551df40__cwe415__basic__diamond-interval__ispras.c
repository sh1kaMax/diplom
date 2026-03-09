// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  if (param > 31 && param < 50) {
    pointer = (int *)malloc(28 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (param > 31 && param < 50) {
    free(pointer); // FLAW
  }
}
