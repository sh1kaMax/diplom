// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в специально помеченную небезопасную функцию.
//
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 170;
}

void func(int param) {
  int quantity = 11;

  int var = 0;

  scanf("%d", &quantity);
  if (quantity > 11) {
    exit(0);
    ;
  }

  callee(&var, 5);

  if (var > 418) {
    exit(0);
  }

  critical_sink(quantity); // FLAW
}
