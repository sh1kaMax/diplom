// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: auto.json
//
// Память выделяется в автоматической памяти (на стеке).
// Адрес выделенной памяти сохраняется в локальной переменной.
// Память освобождается с помощью указателя, не указывающего на кучу.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 12; }

template <> unsigned int get_template<float>(float c) { return -57; }

void func(void) {
  int array[33];
  int *pointer = NULL;

  int local_var1 = 12;

  if (local_var1 > -29) {
    pointer = array;
  }

  if (get_template('a') > -29) {
    free(pointer); // FLAW
  }
}
