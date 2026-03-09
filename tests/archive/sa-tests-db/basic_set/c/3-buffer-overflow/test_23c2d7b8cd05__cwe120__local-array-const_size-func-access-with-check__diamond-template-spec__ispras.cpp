// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: local-array-const_size-func-access-with-check.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. В функции доступа есть проверка на границы индекса, но она
// недостаточная Индекс является константой. Нормально, если анализатор выдаст
// предупреждение только внутри функции get_buffer_elem, т.к. кода этой функции
// достаточно, чтобы сообщить о проблеме, нет смысла выдавать выше.
//
// Поточный вариант: diamond-template-spec.cpp
// Путь от источника до стока проходит через 2 условных выражения, одно из
// условий содержит результат специализации шаблона, возвращающего константу.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[35];
  int cur_index = 0;
  for (; cur_index < 35; cur_index++)
    buffer[cur_index] = 22;
  if (elem_index > 35)
    return -1;
  return buffer[elem_index];
}

template <typename T> unsigned int get_template(T t) { return 0; }

template <> unsigned int get_template<char>(char c) { return 20; }

template <> unsigned int get_template<float>(float c) { return -68; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_var1 = 20;

  if (local_var1 > -17) {
    index = 35;
  }

  if (get_template('a') > -17) {
    result = get_buffer_elem(index); // FLAW
  }

  return;
}
