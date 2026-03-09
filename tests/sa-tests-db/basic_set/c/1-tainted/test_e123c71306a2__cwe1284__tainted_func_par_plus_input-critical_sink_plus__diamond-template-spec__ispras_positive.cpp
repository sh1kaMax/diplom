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
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param + 13);
  malloc_res[0] = 0;
  free(malloc_res);
}

int get_source(int get_source_param) {
  ;
  return get_source_param + 11;
}

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 62; }

template <> unsigned int get_template<float>(float c) { return -6; }

void func(void) {
  int quantity = 132;
  int template_local_var;

  int local_var1 = 62;

  if (local_var1 > 19) {
    scanf("%d", &template_local_var);
    quantity = get_source(template_local_var);
  }

  if (get_template('a') > 19) {
    critical_sink(quantity); // FLAW
  }
}
