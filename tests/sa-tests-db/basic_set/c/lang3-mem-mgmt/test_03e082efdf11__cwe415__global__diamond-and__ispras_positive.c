// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdlib.h>

int *pointer = NULL;

void func(int param) {
  int freed_flag = 0;

  if (param & 0x1D) {
    pointer = (int *)malloc(19 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (param & 0x1D) {
    free(pointer); // FLAW
  }
}
