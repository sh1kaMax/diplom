// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: array-new-delete.json
//
// Память выделяется с помощью оператора new[]
// Память освобождается с помощью оператора delete.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 57; }

template <> unsigned int get_template<float>(float c) { return -51; }

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int local_var1 = 57;

  if (local_var1 > 39) {
    pointer = new int[18];
  }

  if (get_template('a') > 39) {
    delete pointer; // FLAW
  }
}
