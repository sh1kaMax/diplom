// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: call-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается

#include <stdio.h>
#include <stdlib.h>

int callee(int par1) {
  if (par1 > 35)
    return 20;

  return 10;
}

void func(int param) {
  int *pointer = NULL, quantity = 8;

  int local_var = -1;

  scanf("%d", &quantity);
  if (quantity > 8) {
    exit(0);
    ;
  }

  if (callee(local_var) == 10) {
    exit(0);
  }

  pointer = (int *)malloc(quantity * sizeof(int));

  free(pointer);
}
