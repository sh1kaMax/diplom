// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_cond_func_input-critical_sink.json
//
// Количество получено от пользователя в вызываемой функции, если параметр не
// отрицательный. Отсутствуют проверки выхода количества за пределы допустимых
// значений. Количество передаётся в функцию, которая вызывает malloc.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

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

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 87; }

template <> unsigned int get_template<float>(float c) { return -74; }

void func(void) {
  int quantity = 8;
  int template_flag = 55;

  int local_var1 = 87;

  if (local_var1 > 44) {
    quantity = get_source(template_flag);
  }

  if (get_template(0.33) > 44) {
    critical_sink(quantity);
  }
}
