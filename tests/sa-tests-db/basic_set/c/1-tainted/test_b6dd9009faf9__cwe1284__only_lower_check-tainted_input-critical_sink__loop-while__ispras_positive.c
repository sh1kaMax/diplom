// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в специально помеченную небезопасную функцию.
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

void func(void) {
  int quantity = 9;

  int var;

  scanf("%d", &quantity);
  if (quantity <= 0) {
    exit(0);
    ;
  }

  var = 0;

  while (var < 12)
    var++;

  critical_sink(quantity); // FLAW
}
