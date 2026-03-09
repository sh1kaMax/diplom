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
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdlib.h>
#include <string.h>

int *pointer = NULL;

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

int func(int *param) {
  int freed_flag = 0;

  int local_var = 5;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (callee(local_var, 271) > 0) {
    exit(0);
  }

  if (pointer) {
    memcpy(pointer, param, sizeof(int)); // FLAW
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
