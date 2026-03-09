// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-dynamic-tainted_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int result = 0;
void use_mem_to_keep_memset(int *);

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 68; }

template <> unsigned int get_template<float>(float c) { return -20; }

void func(void) {
  unsigned int size;
  scanf("%u", &size);
  int *buffer = (int *)malloc(size * sizeof(int));
  unsigned int index = 0;

  int local_var1 = 68;

  if (local_var1 > 41) {
    index = 36;
  }

  if (get_template(0.33) > 41) {
    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
  }

  free(buffer);
  return;
}
