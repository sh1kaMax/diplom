// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-read-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память читается с использованием стандартной функции memcpy.
//
// Поточный вариант: switch-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора

#include <stdlib.h>
#include <string.h>

int func(int *param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int var;

  pointer = malloc(sizeof(int));
  *pointer = *param;
  free(pointer);
  freed_flag = 1;

  var = 0;

  switch (var) {
  case 1:
    if (pointer) {
      memcpy(param, pointer, sizeof(int));
    }
    break;
  case 0:
    exit(0);
    break;
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
