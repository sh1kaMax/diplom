// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель.
//
// Поточный вариант: virtual-call-2.cpp
// Путь от источника до стока зависит от возвращаемого значения метода,
// вызванного косвенно как метод базового класса

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

class Base {
public:
  Base() {}
  virtual ~Base() {}

  virtual int cond(int par1) const = 0;
};

class Derived : public Base {
public:
  Derived() {}
  ~Derived() {}

  int cond(int par1) const {
    if (par1 > 35)
      return 20;

    return 10;
  }
};

class DerivedSecond : public Base {
public:
  DerivedSecond() {}
  ~DerivedSecond() {}

  int cond(int par1) const { return 100; }
};

class DerivedDerived : public Derived {
public:
  DerivedDerived() {}
  ~DerivedDerived() {}
};

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var = 4;
  const Base &obj = DerivedDerived();

  pointer = NULL;

  if (obj.cond(local_var) > 10) {
    exit(0);
  }

  wrapper(pointer); // FLAW
}