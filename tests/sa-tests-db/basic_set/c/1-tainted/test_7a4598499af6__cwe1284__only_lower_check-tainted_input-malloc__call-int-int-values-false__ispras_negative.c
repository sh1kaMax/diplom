// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdio.h>
#include <stdlib.h>

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(int param) {
  int *pointer = NULL, quantity = 10;

  int local_var = 69;

  scanf("%d", &quantity);
  if (quantity <= 0) {
    exit(0);
    ;
  }

  if (callee(local_var, 171) > 0) {
    exit(0);
  }

  pointer = (int *)malloc(quantity * sizeof(int));

  free(pointer);
}
