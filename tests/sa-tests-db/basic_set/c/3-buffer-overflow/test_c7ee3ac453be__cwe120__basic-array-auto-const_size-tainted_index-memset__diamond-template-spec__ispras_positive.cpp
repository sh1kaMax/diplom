// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-auto-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 22; }

template <> unsigned int get_template<float>(float c) { return -54; }

void func(void) {
  int buffer[33];
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 22;

  if (local_var1 > -1) {
    scanf("%u", &index);
  }

  if (get_template('a') > -1) {
    memset(buffer, 0, index * sizeof(int)); // FLAW
    use_mem_to_keep_memset(buffer);
  }

  return;
}
