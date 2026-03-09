// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <stdio.h>
#include <stdlib.h>

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 456;
}

void func(int param) {
  int *pointer = NULL, quantity = 10;

  int var = 0;

  scanf("%d", &quantity);

  callee(&var, 9);

  if (var > 880) {
    exit(0);
  }

  pointer = (int *)malloc(quantity * sizeof(int)); // FLAW

  free(pointer);
}
