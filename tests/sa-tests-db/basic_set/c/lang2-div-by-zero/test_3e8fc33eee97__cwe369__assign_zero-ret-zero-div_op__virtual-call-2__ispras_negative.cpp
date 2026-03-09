// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: virtual-call-2.cpp
// Путь от источника до стока зависит от возвращаемого значения метода,
// вызванного косвенно как метод базового класса

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

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

  int cond(int par1) const { return 100; }
};

class DerivedSecond : public Base {
public:
  DerivedSecond() {}
  ~DerivedSecond() {}

  int cond(int par1) const {
    if (par1 > 50)
      return 20;

    return 10;
  }
};

class DerivedDerived : public Derived {
public:
  DerivedDerived() {}
  ~DerivedDerived() {}
};

void func(void) {
  int divident = 25, divisor = 8, result;

  int local_var = -2;
  const Base &obj = DerivedDerived();

  divisor = wrapper(23);

  if (obj.cond(local_var) > 10) {
    exit(0);
  }

  result = divident / divisor;
}