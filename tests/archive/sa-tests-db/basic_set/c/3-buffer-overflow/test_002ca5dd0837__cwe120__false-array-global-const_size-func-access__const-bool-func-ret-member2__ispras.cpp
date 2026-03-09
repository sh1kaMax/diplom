// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
//
// Поточный вариант: const-bool-func-ret-member2.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// значение члена класса. Значение устанавливается вначале в false, затем в
// true. Но установка в true происходит после проверки. Поэтому путь недостижим.

#include <stdlib.h>

int buffer[40];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

class SomeClass {
  bool member_flag;

public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return member_flag; }

void SomeClass::func(void) {
  int result = 0;
  unsigned int index = 0;

  member_flag = false;

  index = 40;

  if (isTrue()) {
    member_flag = true;
    result = get_buffer_elem(index);
  }

  return;
}
