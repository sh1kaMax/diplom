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
// Поточный вариант: class-member-class.cpp
// Тест содержит 2 класса. Один из классов содержит указатель на другой класс.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[32];
  int cur_index = 0;
  for (; cur_index < 32; cur_index++)
    buffer[cur_index] = 25;
  if (elem_index >= 32)
    return -1;
  return buffer[elem_index];
}

class Class1 {
  int member1;

public:
  Class1(int ctor_par) : member1(ctor_par) {}

  void setVal(int set_val_par) { member1 = set_val_par; }

  int getVal() { return member1; }
};

class Class2 {
  int member1;
  Class1 *member2;

public:
  Class2(int ctor_par) : member1(ctor_par) { member2 = new Class1(ctor_par); }

  ~Class2() { delete member2; }

  void setVal(int set_val_par) { member1 = set_val_par; }

  void setVal(Class1 *set_val_par) {
    delete member2;
    member2 = set_val_par;
  }

  int getVal1() { return member1; }

  int getVal2() { return member2->getVal(); }
};

void func(void) {
  int result = 0;
  unsigned int index = 0;

  Class1 *cl_var1 = new Class1(94);
  Class2 *cl_var2 = new Class2(65);

  index = 32;

  cl_var1->setVal(-17);
  cl_var2->setVal(166);
  cl_var2->setVal(cl_var1);

  if (cl_var2->getVal2() < -16) {
    result = get_buffer_elem(index);
  }

  delete cl_var2;

  return;
}
