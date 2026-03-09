// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: malloc-delete.json
//
// Память выделяется с помощью стандартной функции malloc.
// Память освобождается с помощью оператора delete.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 9; }

template <> unsigned int get_template<float>(float c) { return -85; }

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int local_var1 = 9;

  if (local_var1 > 2) {
    pointer = (int *)malloc(26 * sizeof(int));
  }

  if (get_template('a') > 2) {
    delete pointer; // FLAW
  }
}
