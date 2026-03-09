// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int *pointer = NULL;

void func(int param) {
  int freed_flag = 0;

  if (param > 9 && param < 21) {
    pointer = (int *)malloc(14 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (param > 9 && param < 21) {
    free(pointer); // FLAW
  }
}
