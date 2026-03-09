// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: virtual-call-0.cpp
// Путь от источника до стока зависит от возвращаемого значения метода,
// вызванного косвенно как метод базового класса

#include <stdlib.h>

class Base {
public:
  Base() {}
  virtual ~Base() {}

  virtual int cond(int par1) = 0;
};

class Derived : public Base {
public:
  Derived() {}
  ~Derived() {}

  int cond(int par1) {
    if (par1 > 21)
      return 20;

    return 10;
  }
};

class DerivedSecond : public Base {
public:
  DerivedSecond() {}
  ~DerivedSecond() {}

  int cond(int par1) { return 100; }
};

void func(void) {
  float divident = 17.37, divisor = 15.32, result;

  int local_var = 3;
  Base *obj = new Derived();

  divisor = 0.0;

  if (obj->cond(local_var) > 10) {
    exit(0);
  }

  result = divident / divisor; // FLAW

  delete obj;
}
