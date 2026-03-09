// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 19; }

template <> unsigned int get_template<float>(float c) { return -82; }

void func(void) {
  int *pointer = NULL, quantity = 11;

  int local_var1 = 19;

  if (local_var1 > -4) {
    scanf("%d", &quantity);
    if (quantity > 11) {
      exit(0);
      ;
    }
  }

  if (get_template('a') > -4) {
    pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
  }

  free(pointer);
}
