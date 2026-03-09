// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в функцию, которая вызывает malloc.
//
// Поточный вариант: ternary.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними с помощью тернарного оператора, выполнение достигает стока в
// случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

void func(void) {
  int quantity = 11;

  int var;

  scanf("%d", &quantity);

  var = ((quantity <= 0 || quantity > 11) ? 1 : 0);

  if (var) {
    critical_sink(quantity); // FLAW
  }
}
