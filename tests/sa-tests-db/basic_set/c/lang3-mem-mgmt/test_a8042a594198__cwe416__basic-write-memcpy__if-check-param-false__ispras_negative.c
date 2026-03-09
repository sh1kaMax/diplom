// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-write-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память записывается с использованием стандартной функции
// memcpy.
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции

#include <stdlib.h>
#include <string.h>

int func(int *param, int param2) {
  int *pointer = NULL;
  int freed_flag = 0;

  free(pointer);
  freed_flag = 1;

  if (param2 > 27 && param2 < 28) {
    if (pointer) {
      memcpy(pointer, param, sizeof(int));
    }
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
