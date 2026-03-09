// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_cond_func_input-critical_sink.json
//
// Количество получено от пользователя в вызываемой функции, если параметр не
// отрицательный. Отсутствуют проверки выхода количества за пределы допустимых
// значений. Количество передаётся в функцию, которая вызывает malloc.
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

int get_source(int flag_param) {
  ;
  if (flag_param < 0)
    return 1;
  int get_source_var;
  scanf("%d", &get_source_var);
  return get_source_var;
}

void func(void) {
  int quantity = 13;
  int template_flag = 96;

  int var;

  quantity = get_source(template_flag);

  var = 0;

  while (var < 18)
    var++;

  critical_sink(quantity); // FLAW
}
