// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-read-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память читается с использованием стандартной функции memcpy.
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции

#include <stdlib.h>
#include <string.h>

int *pointer = NULL;

int func(int *param, int param2) {
  int freed_flag = 0;

  pointer = malloc(sizeof(int));
  *pointer = *param;
  free(pointer);
  freed_flag = 1;

  if (param2 > 13 && param2 < 14) {
    if (pointer) {
      memcpy(param, pointer, sizeof(int));
    }
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
