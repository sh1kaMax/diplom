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
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param, int func_flag) {
  if (func_flag < 0)
    return;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 76; }

template <> unsigned int get_template<float>(float c) { return -85; }

void func(void) {
  int quantity = 20;
  int template_flag = 69;

  int local_var1 = 76;

  if (local_var1 > 36) {
    scanf("%d", &quantity);
  }

  if (get_template(0.33) > 36) {
    critical_sink(quantity, template_flag);
  }
}
