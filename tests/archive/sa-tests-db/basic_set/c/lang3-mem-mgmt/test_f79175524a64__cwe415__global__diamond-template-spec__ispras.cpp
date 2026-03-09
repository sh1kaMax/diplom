// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int *pointer = NULL;

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 48; }

template <> unsigned int get_template<float>(float c) { return -83; }

void func(void) {
  int freed_flag = 0;

  int local_var1 = 48;

  if (local_var1 > 43) {
    pointer = (int *)malloc(26 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (get_template('a') > 43) {
    free(pointer); // FLAW
  }
}
