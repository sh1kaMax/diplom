// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: class-member-class.cpp
// Тест содержит 2 класса. Один из классов содержит указатель на другой класс.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 76; }

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
  int divident = 60, divisor = 7, result;

  Class1 *cl_var1 = new Class1(31);
  Class2 *cl_var2 = new Class2(88);

  divisor = wrapper(15);
  divisor -= 74;

  cl_var1->setVal(-26);
  cl_var2->setVal(111);
  cl_var2->setVal(cl_var1);

  if (cl_var2->getVal2() < -23) {
    result = divident / divisor;
  }

  delete cl_var2;
}
