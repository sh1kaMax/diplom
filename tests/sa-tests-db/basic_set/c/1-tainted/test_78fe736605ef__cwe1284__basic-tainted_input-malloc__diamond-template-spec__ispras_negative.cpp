// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 99; }

template <> unsigned int get_template<float>(float c) { return -16; }

void func(void) {
  int *pointer = NULL, quantity = 12;

  int local_var1 = 99;

  if (local_var1 > 93) {
    scanf("%d", &quantity);
  }

  if (get_template(0.33) > 93) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}
