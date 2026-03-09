// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-read-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память читается с использованием стандартной функции memcpy.
//
// Поточный вариант: call-pointer.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой непосредственно передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение нулевое,
// поэтому проверка в вызывающей функции неуспешна и выполнение достигает стока

#include <stdlib.h>
#include <string.h>

int callee(int *pointer_param) {
  if (*pointer_param > 0)
    return 1;
  else
    return 0;
}

int func(int *param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int var = 0;

  pointer = malloc(sizeof(int));
  *pointer = *param;
  free(pointer);
  freed_flag = 1;

  if (callee(&var)) {
    exit(0);
  }

  if (pointer) {
    memcpy(param, pointer, sizeof(int)); // FLAW
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
