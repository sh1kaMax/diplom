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

template <> unsigned int get_template<char>(char c) { return 12; }

template <> unsigned int get_template<float>(float c) { return -26; }

void func(void) {
  int *pointer = NULL, quantity = 9;

  int local_var1 = 12;

  if (local_var1 > -10) {
    scanf("%d", &quantity);
    if (quantity > 9) {
      exit(0);
      ;
    }
  }

  if (get_template(0.33) > -10) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}
