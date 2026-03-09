// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-static-const_size-const_index-direct_ref.json
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

int result = 0;
int buffer[40];

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 73; }

template <> unsigned int get_template<float>(float c) { return -18; }

void func(void) {
  unsigned int index = 0;

  int local_var1 = 73;

  if (local_var1 > 40) {
    index = 40;
  }

  if (get_template('a') > 40) {
    result = buffer[index]; // FLAW
  }

  return;
}
