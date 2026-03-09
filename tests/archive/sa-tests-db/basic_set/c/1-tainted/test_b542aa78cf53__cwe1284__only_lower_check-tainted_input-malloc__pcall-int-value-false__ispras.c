// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: pcall-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается. Вызов функции осуществляется с помощью
// указателя.

#include <stdio.h>
#include <stdlib.h>

int callee(int par1) {
  if (par1 > 52)
    return 20;

  return 10;
}

void func(void) {
  int *pointer = NULL, quantity = 13;

  int local_var = 3;
  int (*func_ptr)(int) = &callee;

  scanf("%d", &quantity);
  if (quantity <= 0) {
    exit(0);
    ;
  }

  if (func_ptr(local_var) == 10) {
    exit(0);
  }

  pointer = (int *)malloc(quantity * sizeof(int));

  free(pointer);
}
