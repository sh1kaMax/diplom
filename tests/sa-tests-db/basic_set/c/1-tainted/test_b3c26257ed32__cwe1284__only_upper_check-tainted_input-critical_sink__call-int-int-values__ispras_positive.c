// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в специально помеченную небезопасную функцию.
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

void func(int param) {
  int quantity = 10;

  int local_var = 85;

  scanf("%d", &quantity);
  if (quantity > 10) {
    exit(0);
    ;
  }

  if (callee(local_var, 110) > 0) {
    exit(0);
  }

  critical_sink(quantity); // FLAW
}
