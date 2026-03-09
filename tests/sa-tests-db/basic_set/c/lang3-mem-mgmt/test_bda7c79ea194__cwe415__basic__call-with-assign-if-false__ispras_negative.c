// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdlib.h>

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 293;
}

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int var = 0;

  pointer = (int *)malloc(16 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  callee(&var, 1);

  if (var > 139) {
    exit(0);
  }

  free(pointer);
}
