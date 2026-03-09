// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-tainted_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>

int result = 0;

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 25; }

template <> unsigned int get_template<float>(float c) { return -22; }

void func(void) {
  unsigned int size;
  scanf("%u", &size);
  int *buffer = (int *)malloc(size * sizeof(int));
  unsigned int index = 0;

  int local_var1 = 25;

  if (local_var1 > 12) {
    scanf("%u", &index);
  }

  if (get_template(0.33) > 12) {
    result = buffer[index];
  }

  free(buffer);
  return;
}
