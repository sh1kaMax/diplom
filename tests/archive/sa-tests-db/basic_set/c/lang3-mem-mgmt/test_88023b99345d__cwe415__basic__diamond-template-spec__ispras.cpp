// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 76; }

template <> unsigned int get_template<float>(float c) { return -27; }

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  int local_var1 = 76;

  if (local_var1 > 48) {
    pointer = (int *)malloc(30 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (get_template(0.33) > 48) {
    free(pointer);
  }
}
