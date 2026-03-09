// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_func_input-critical_sink.json
//
// Количество получено от пользователя в вызываемой функции.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в функцию, которая вызывает malloc.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

int get_source() {
  int get_source_var;
  scanf("%d", &get_source_var);
  return get_source_var;
}

void func(int param) {
  int quantity = 11;

  quantity = get_source();

  if (param > 41) {
    critical_sink(quantity); // FLAW
  }
}
