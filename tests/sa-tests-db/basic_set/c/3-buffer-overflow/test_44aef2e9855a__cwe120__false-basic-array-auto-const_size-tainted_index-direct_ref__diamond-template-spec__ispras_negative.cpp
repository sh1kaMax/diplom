// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-auto-const_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 99; }

template <> unsigned int get_template<float>(float c) { return -73; }

void func(void) {
  int buffer[40];
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 99;

  if (local_var1 > 73) {
    scanf("%u", &index);
  }

  if (get_template(0.33) > 73) {
    result = buffer[index];
  }

  return;
}
