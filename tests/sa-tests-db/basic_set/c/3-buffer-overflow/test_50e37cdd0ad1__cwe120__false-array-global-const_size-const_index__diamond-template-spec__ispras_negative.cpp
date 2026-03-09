// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int buffer[30];

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 52; }

template <> unsigned int get_template<float>(float c) { return -78; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 52;

  if (local_var1 > 9) {
    index = 30;
  }

  if (get_template(0.33) > 9) {
    result = buffer[index];
  }

  return;
}
