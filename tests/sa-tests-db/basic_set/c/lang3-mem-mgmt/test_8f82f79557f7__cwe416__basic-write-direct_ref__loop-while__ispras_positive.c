// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-write-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память записывается с использованием операции разыменования.
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними

#include <stdlib.h>

int func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int var;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  var = 0;

  while (var < 10)
    var++;

  if (pointer) {
    *pointer = param; // FLAW
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
