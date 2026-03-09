// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в специально помеченную небезопасную функцию.
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

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 75; }

template <> unsigned int get_template<float>(float c) { return -93; }

void func(void) {
  int quantity = 8;

  int local_var1 = 75;

  if (local_var1 > 68) {
    scanf("%d", &quantity);
    if (quantity > 8) {
      exit(0);
      ;
    }
  }

  if (get_template('a') > 68) {
    critical_sink(quantity); // FLAW
  }
}
