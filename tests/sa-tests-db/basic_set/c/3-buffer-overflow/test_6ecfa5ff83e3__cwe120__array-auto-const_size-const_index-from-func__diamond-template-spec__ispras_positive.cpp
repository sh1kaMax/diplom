// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 4; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 88; }

template <> unsigned int get_template<float>(float c) { return -53; }

void func(void) {
  int buffer[35];
  unsigned int index = 0;

  int local_var1 = 88;

  if (local_var1 > 78) {
    index = 35;
  }

  if (get_template('a') > 78) {
    index = index_change_func(index);
    result = buffer[index]; // FLAW
  }

  return;
}
