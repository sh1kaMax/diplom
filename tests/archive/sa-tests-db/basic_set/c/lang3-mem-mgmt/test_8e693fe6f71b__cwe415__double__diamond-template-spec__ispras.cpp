// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 56; }

template <> unsigned int get_template<float>(float c) { return -89; }

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int local_var1 = 56;

  if (local_var1 > 44) {
    pointer1 = (int *)malloc(17 * sizeof(int));
    pointer2 = (int *)malloc(17 * sizeof(int));
    free(pointer2);
    freed_flag = 1;
  }

  if (get_template('a') > 44) {
    free(pointer1);
    free(pointer2); // FLAW
    pointer1 = NULL;
  }

  free(pointer1);
}
