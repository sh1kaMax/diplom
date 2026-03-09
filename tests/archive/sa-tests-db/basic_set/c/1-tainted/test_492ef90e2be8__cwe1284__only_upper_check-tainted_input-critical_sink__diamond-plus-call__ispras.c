// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в специально помеченную небезопасную функцию.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

int ret_func(int param1) { return param1; }

void func(int param) {
  int quantity = 9;

  int func_res = ret_func(10);

  if (param + func_res > 40) {
    scanf("%d", &quantity);
    if (quantity > 9) {
      exit(0);
      ;
    }
  }

  if (param + func_res > 40) {
    critical_sink(quantity); // FLAW
  }
}
