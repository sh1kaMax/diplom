// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: call-with-no-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

int *pointer = NULL;

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 116;
}

void func(int param) {
  int freed_flag = 0;

  int var = 0;

  pointer = (int *)malloc(21 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  callee(&var, -9);

  if (var > 313) {
    exit(0);
  }

  free(pointer); // FLAW
}
