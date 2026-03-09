// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_func_input-critical_sink.json
//
// Количество получено от пользователя в вызываемой функции.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в функцию, которая вызывает malloc.
//
// Поточный вариант: call-with-no-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

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

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 98;
}

void func(void) {
  int quantity = 8;

  int var = 0;

  quantity = get_source();

  callee(&var, -7);

  if (var > 428) {
    exit(0);
  }

  critical_sink(quantity); // FLAW
}
