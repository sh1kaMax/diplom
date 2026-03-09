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
// Поточный вариант: call-global.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения глобальной переменной, значение которой
// устанавливается перед вызовом; возвращаемое из вызываемой функции значение
// нулевое, поэтому проверка в вызывающей функции неуспешна и выполнение
// достигает стока.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param, int func_flag) {
  if (func_flag < 0)
    return;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

int global_var = 0;

int callee(void) {
  if (global_var > 0)
    return 1;
  else
    return 0;
}

void func(void) {
  int quantity = 16;
  int template_flag = 31;

  global_var = -1;

  scanf("%d", &quantity);

  if (callee()) {
    exit(0);
  }

  critical_sink(quantity, template_flag); // FLAW
}
