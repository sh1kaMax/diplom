// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>

int ret_func(int param1) { return param1; }

void func(int param) {
  int *pointer = NULL, quantity = 19;

  int func_res = ret_func(10);

  if (param + func_res > 37) {
    scanf("%d", &quantity);
    if (quantity > 19) {
      exit(0);
      ;
    }
  }

  if (param + func_res < 37) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}
