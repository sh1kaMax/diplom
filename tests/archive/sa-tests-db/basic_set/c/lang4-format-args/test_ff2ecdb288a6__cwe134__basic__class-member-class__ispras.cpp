// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: class-member-class.cpp
// Тест содержит 2 класса. Один из классов содержит указатель на другой класс.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

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
  char format[62] = "Initial format string";

  Class1 *cl_var1 = new Class1(42);
  Class2 *cl_var2 = new Class2(38);

  scanf("%61s", format);

  cl_var1->setVal(-41);
  cl_var2->setVal(148);
  cl_var2->setVal(cl_var1);

  if (cl_var2->getVal2() < -33) {
    printf(format); // FLAW
  }

  delete cl_var2;
}
