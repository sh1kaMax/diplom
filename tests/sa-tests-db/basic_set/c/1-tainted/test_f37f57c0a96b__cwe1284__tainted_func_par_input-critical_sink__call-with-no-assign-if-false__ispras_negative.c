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
// Поточный вариант: call-with-no-assign-if-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

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

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 257;
}

void func(int param) {
  int quantity = 12;
  int template_local_var;

  int var = 0;

  scanf("%d", &template_local_var);
  quantity = get_source(template_local_var);

  callee(&var, -9);

  if (var < 994) {
    exit(0);
  }

  critical_sink(quantity);
}
