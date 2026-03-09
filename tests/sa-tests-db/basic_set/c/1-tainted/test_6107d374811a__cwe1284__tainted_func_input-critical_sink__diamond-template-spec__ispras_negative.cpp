// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_func_input-critical_sink.json
//
// Количество получено от пользователя в вызываемой функции.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в функцию, которая вызывает malloc.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

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

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 15; }

template <> unsigned int get_template<float>(float c) { return -98; }

void func(void) {
  int quantity = 18;

  int local_var1 = 15;

  if (local_var1 > -31) {
    quantity = get_source();
  }

  if (get_template(0.33) > -31) {
    critical_sink(quantity);
  }
}
