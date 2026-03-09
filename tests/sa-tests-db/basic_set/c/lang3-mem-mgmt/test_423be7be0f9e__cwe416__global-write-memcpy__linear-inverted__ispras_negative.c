// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-write-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память записывается с использованием стандартной функции
// memcpy.
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока

#include <stdlib.h>
#include <string.h>

int *pointer = NULL;

int func(int *param) {
  int freed_flag = 0;

  if (pointer) {
    memcpy(pointer, param, sizeof(int));
  }

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
