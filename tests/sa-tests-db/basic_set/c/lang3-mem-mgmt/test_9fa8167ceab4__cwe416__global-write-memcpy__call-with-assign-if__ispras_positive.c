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
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <stdlib.h>
#include <string.h>

int *pointer = NULL;

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 345;
}

int func(int *param) {
  int freed_flag = 0;

  int var = 0;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  callee(&var, 2);

  if (var > 598) {
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
