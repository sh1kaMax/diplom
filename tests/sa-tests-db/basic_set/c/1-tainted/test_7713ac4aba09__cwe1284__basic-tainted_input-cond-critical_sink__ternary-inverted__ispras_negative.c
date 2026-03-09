// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-cond-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в функцию, которая вызывает malloc в зависимости от
// флага.
//
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param, int func_flag) {
  if (func_flag < 0)
    return;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

void func(void) {
  int quantity = 15;
  int template_flag = 13;

  int var;

  scanf("%d", &quantity);

  var = ((quantity <= 0 || quantity > 15) ? 0 : 1);

  if (var) {
    critical_sink(quantity, template_flag);
  }
}
