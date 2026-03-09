// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-write-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память записывается с использованием операции разыменования.
//
// Поточный вариант: call-pointer-alias.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой сначала сохраняется в локальную
// переменную-указатель, а затем с его помощью передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение нулевое,
// поэтому проверка в вызывающей функции неуспешна и выполнение достигает стока

#include <stdlib.h>

int callee(int *pointer_param) {
  if (*pointer_param > 0)
    return 1;
  else
    return 0;
}

int func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int local_var = 0, *local_pointer = &local_var;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (callee(local_pointer)) {
    exit(0);
  }

  if (pointer) {
    *pointer = param; // FLAW
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
