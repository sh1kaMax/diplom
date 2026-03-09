// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 329; }

void func(void) {
  int *pointer = NULL, quantity = 14;

  int var = 0;

  scanf("%d", &quantity);
  if (quantity > 14) {
    exit(0);
    ;
  }

  callee(&var);

  if (var > 792) {
    exit(0);
  }

  pointer = (int *)malloc(quantity * sizeof(int)); // FLAW

  free(pointer);
}
