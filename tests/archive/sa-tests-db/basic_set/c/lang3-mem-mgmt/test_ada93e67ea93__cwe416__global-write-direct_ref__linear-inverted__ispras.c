// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-write-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память записывается с использованием операции разыменования.
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока

#include <stdlib.h>

int *pointer = NULL;

int func(int param) {
  int freed_flag = 0;

  if (pointer) {
    *pointer = param;
  }

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
