// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-read-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память читается с использованием стандартной функции memcpy.
//
// Поточный вариант: call-global.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения глобальной переменной, значение которой
// устанавливается перед вызовом; возвращаемое из вызываемой функции значение
// нулевое, поэтому проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdlib.h>
#include <string.h>

int *pointer = NULL;

int global_var = 0;

int callee(void) {
  if (global_var > 0)
    return 1;
  else
    return 0;
}

int func(int *param) {
  int freed_flag = 0;

  global_var = -1;

  pointer = malloc(sizeof(int));
  *pointer = *param;
  free(pointer);
  freed_flag = 1;

  if (callee()) {
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
