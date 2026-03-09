// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-auto-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
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

template <> unsigned int get_template<char>(char c) { return 25; }

template <> unsigned int get_template<float>(float c) { return -63; }

void func(void) {
  int buffer[40];
  unsigned int index = 0;

  int local_var1 = 25;

  if (local_var1 > 17) {
    index = 40;
  }

  if (get_template('a') > 17) {
    result = buffer[index]; // FLAW
  }

  return;
}
