// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int result = 0;

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 89; }

template <> unsigned int get_template<float>(float c) { return -91; }

void func(void) {
  int *buffer = (int *)malloc(39 * sizeof(int));
  unsigned int index = 0;

  int local_var1 = 89;

  if (local_var1 > 49) {
    index = 39;
  }

  if (get_template(0.33) > 49) {
    result = buffer[index];
  }

  free(buffer);
  return;
}
