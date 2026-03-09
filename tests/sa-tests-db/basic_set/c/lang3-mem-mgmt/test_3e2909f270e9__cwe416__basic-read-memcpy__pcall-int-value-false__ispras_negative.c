// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-read-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память читается с использованием стандартной функции memcpy.
//
// Поточный вариант: pcall-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение не достигает стока. Вызов функции осуществляется с
// помощью указателя.

#include <stdlib.h>
#include <string.h>

int callee(int par1) {
  if (par1 > 108)
    return 20;

  return 10;
}

int func(int *param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int (*func_ptr)(int) = &callee;
  int other = 108 - 1;

  pointer = malloc(sizeof(int));
  *pointer = *param;
  free(pointer);
  freed_flag = 1;

  if (func_ptr(other) <= 10) {
    exit(0);
  }

  if (pointer) {
    memcpy(param, pointer, sizeof(int));
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
