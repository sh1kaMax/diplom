// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_func_par_plus_input-critical_sink_plus.json
//
// Количество получено от пользователя и присваивается в переменную через вызов
// функции, возвращающую сумму константы со своим аргументом. Отсутствуют
// проверки выхода количества за пределы допустимых значений. Количество
// передаётся в функцию, которая вызывает malloc, передавая в качестве параметра
// сумму аргумента и константы.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param + 18);
  malloc_res[0] = 0;
  free(malloc_res);
}

int get_source(int get_source_param) {
  ;
  return get_source_param + 13;
}

void func(void) {
  int quantity = 156;
  int template_local_var;

  int var, var2;

  scanf("%d", &template_local_var);
  quantity = get_source(template_local_var);

  for (var = 0; var < 19; var++) {
    for (var2 = var; var2 < 12; var2++) {
      critical_sink(quantity); // FLAW
    }
  }
}
