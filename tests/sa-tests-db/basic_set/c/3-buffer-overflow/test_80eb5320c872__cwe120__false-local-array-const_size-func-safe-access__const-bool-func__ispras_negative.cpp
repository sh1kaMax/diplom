// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-local-array-const_size-func-safe-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. В функции доступа есть проверка на границы индекса. Индекс
// является константой.
//
// Поточный вариант: const-bool-func.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// true.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[28];
  int cur_index = 0;
  for (; cur_index < 28; cur_index++)
    buffer[cur_index] = 73;
  if (elem_index >= 28)
    return -1;
  return buffer[elem_index];
}

class SomeClass {
public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return true; }

void SomeClass::func(void) {
  int result = 0;
  unsigned int index = 0;

  index = 28;

  if (isTrue()) {
    result = get_buffer_elem(index);
  }

  return;
}
