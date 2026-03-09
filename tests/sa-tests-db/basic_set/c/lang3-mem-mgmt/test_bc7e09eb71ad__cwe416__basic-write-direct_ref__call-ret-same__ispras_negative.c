// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-write-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память записывается с использованием операции разыменования.
//
// Поточный вариант: call-ret-same.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая просто возвращает свой аргумент. Поэтому проверка в
// вызывающей функции успешна и выполнение не достигает стока

#include <stdlib.h>

int callee(int par1) { return par1; }

int func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int local_res = callee(param);

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (local_res == param) {
    exit(0);
  }

  if (pointer) {
    *pointer = param;
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
