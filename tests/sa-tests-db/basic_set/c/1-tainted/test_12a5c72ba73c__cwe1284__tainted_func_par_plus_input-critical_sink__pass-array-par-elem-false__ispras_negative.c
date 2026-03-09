// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_func_par_plus_input-critical_sink.json
//
// Количество получено от пользователя и присваивается в переменную через вызов
// функции, возвращающую сумму константы со своим аргументом. Отсутствуют
// проверки выхода количества за пределы допустимых значений. Количество
// передаётся в функцию, которая вызывает malloc.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

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
  return get_source_param + 10;
}

void func(int param) {
  int quantity = 16;
  int template_local_var;

  int arr[100];
  int some_var = 38;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[75] = 0;

  if (some_var) {
    scanf("%d", &template_local_var);
    quantity = get_source(template_local_var);
  }

  if (arr[75]) {
    critical_sink(quantity);
  }
}
