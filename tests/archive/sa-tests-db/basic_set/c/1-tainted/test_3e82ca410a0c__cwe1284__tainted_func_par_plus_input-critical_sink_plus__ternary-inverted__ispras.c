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
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param + 17);
  malloc_res[0] = 0;
  free(malloc_res);
}

int get_source(int get_source_param) {
  ;
  return get_source_param + 17;
}

void func(void) {
  int quantity = 192;
  int template_local_var;

  int var;

  scanf("%d", &template_local_var);
  quantity = get_source(template_local_var);

  var = ((quantity <= 0 || quantity > 192) ? 0 : 1);

  if (var) {
    critical_sink(quantity);
  }
}
