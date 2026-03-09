// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-div_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: virtual-call-3.cpp
// Путь от источника до стока зависит от возвращаемого значения метода,
// вызванного косвенно как метод базового класса

#include <stdlib.h>

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
    if (par1 > 27)
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

void func(void) {
  int divident = 65, divisor = 9, result;

  int local_var = 4;
  const Base &obj = DerivedSecond();

  divisor = 0;

  if (obj.cond(local_var) > 10) {
    exit(0);
  }

  result = divident / divisor;
}