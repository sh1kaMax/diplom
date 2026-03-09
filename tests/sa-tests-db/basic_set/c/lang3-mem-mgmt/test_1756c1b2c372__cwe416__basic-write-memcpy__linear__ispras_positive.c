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
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока

#include <stdlib.h>
#include <string.h>

int func(int *param) {
  int *pointer = NULL;
  int freed_flag = 0;

  free(pointer);
  freed_flag = 1;

  if (pointer) {
    memcpy(pointer, param, sizeof(int)); // FLAW
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
