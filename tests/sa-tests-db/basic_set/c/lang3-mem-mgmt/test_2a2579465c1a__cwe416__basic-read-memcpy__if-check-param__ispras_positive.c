// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-read-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память читается с использованием стандартной функции memcpy.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции

#include <stdlib.h>
#include <string.h>

int func(int *param, int param2) {
  int *pointer = NULL;
  int freed_flag = 0;

  pointer = malloc(sizeof(int));
  *pointer = *param;
  free(pointer);
  freed_flag = 1;

  if (param2 > 33) {
    if (pointer) {
      memcpy(param, pointer, sizeof(int)); // FLAW
    }
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
