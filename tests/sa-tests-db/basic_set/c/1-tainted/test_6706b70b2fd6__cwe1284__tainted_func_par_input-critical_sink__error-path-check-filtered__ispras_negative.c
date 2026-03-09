// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_func_par_input-critical_sink.json
//
// Количество получено от пользователя и присваивается в переменную через вызов
// функции, возвращающую свой аргумент. Отсутствуют проверки выхода количества
// за пределы допустимых значений. Количество передаётся в функцию, которая
// вызывает malloc.
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

int get_source(int get_source_param) {
  ;
  return get_source_param;
}

void func(void) {
  int quantity = 13;
  int template_local_var;

  scanf("%d", &template_local_var);
  quantity = get_source(template_local_var);

  if ((quantity <= 0 || quantity > 13)) {

    quantity = 13;

    goto error_label;
  }

  exit(0);

error_label:
  critical_sink(quantity);
}
