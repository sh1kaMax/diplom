// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: wrapper-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Указатель на буфер получен с помощью вызова функции, которая всегда
// возвращает буфер. Доступ к буферу осуществляется через указатель (с помощью
// операции индексации). Индекс является константой.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int buffer[33];
int *get_buffer_func() { return buffer; }

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 69; }

template <> unsigned int get_template<float>(float c) { return -89; }

void func(void) {
  int result = 0;
  unsigned int index = 0;
  int *buf_ptr;

  int local_var1 = 69;

  if (local_var1 > 56) {
    index = 33;
  }

  if (get_template('a') > 56) {
    buf_ptr = get_buffer_func();
    result = buf_ptr[index]; // FLAW
  }

  return;
}
