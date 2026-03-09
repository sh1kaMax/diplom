// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Память освобождается с помощью указателя, указывающего не на начало
// выделенного блока.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 84; }

template <> unsigned int get_template<float>(float c) { return -63; }

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  int local_var1 = 84;

  if (local_var1 > 73) {
    pointer1 = (int *)malloc(20 * sizeof(int));
    pointer2 = pointer1 + 10;
  }

  if (get_template(0.33) > 73) {
    free(pointer2);
  }
}
