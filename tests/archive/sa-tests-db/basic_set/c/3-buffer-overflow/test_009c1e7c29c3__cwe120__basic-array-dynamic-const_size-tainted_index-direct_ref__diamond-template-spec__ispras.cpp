// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// basic-array-dynamic-const_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 3; }

template <> unsigned int get_template<float>(float c) { return -46; }

void func(void) {
  int *buffer = (int *)malloc(28 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 3;

  if (local_var1 > -31) {
    scanf("%u", &index);
  }

  if (get_template('a') > -31) {
    result = buffer[index]; // FLAW
  }

  free(buffer);
  return;
}
