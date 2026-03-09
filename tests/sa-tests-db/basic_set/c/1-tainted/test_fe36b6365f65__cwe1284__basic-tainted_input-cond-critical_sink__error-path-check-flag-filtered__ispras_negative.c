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
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

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
  int quantity = 13;
  int template_flag = 61;

  int flag = 0;

  scanf("%d", &quantity);

  if ((quantity <= 0 || quantity > 13))
    flag = 1;

  if (flag != 0) {

    template_flag = -template_flag;

    goto error_label;
  }

  exit(0);

error_label:
  critical_sink(quantity, template_flag);
}
