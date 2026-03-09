// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint32.json
//
// Беззнаковое значение задается с помощью константы UINT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: class-member-class.cpp
// Тест содержит 2 класса. Один из классов содержит указатель на другой класс.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
  uint32_t data = 0;
  uint32_t result;

  Class1 *cl_var1 = new Class1(60);
  Class2 *cl_var2 = new Class2(64);

  data = UINT_MAX;

  cl_var1->setVal(-19);
  cl_var2->setVal(147);
  cl_var2->setVal(cl_var1);

  if (cl_var2->getVal2() > -9) {
    result = data + 1;
  }

  delete cl_var2;
}
