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
// Поточный вариант: setter-getter.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает bool
// значение, зависящее от члена класса. Есть setter, который это значение
// выставляет.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[40];
  int cur_index = 0;
  for (; cur_index < 40; cur_index++)
    buffer[cur_index] = 1;
  if (elem_index > 40)
    return -1;
  return buffer[elem_index];
}

class SomeClass {
  int member_flag;

public:
  bool isTrue();

  void setVal(int set_val_par);

  void func(void);
};

bool SomeClass::isTrue() { return member_flag > 16; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  int result = 0;
  unsigned int index = 0;

  setVal(13);

  index = 40;

  setVal(26);

  if (isTrue()) {
    setVal(30);

    result = get_buffer_elem(index); // FLAW
  }

  return;
}
