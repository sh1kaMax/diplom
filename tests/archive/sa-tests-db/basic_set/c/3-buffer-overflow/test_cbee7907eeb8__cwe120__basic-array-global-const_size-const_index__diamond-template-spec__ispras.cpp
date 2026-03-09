// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-global-const_size-const_index.json
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

int buffer[35];

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 100; }

template <> unsigned int get_template<float>(float c) { return -67; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 100;

  if (local_var1 > 62) {
    index = 35;
  }

  if (get_template('a') > 62) {
    result = buffer[index]; // FLAW
  }

  return;
}
