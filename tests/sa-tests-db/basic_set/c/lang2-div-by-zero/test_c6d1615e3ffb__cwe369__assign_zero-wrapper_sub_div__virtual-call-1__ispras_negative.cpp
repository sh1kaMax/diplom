// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: virtual-call-1.cpp
// Путь от источника до стока зависит от возвращаемого значения метода,
// вызванного косвенно как метод базового класса

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1689 / (wrapper_par - 12); }

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

  int cond(int par1) { return 100; }
};

class DerivedSecond : public Base {
public:
  DerivedSecond() {}
  ~DerivedSecond() {}

  int cond(int par1) {
    if (par1 > 38)
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
  int divident = 34, divisor = 9, result;

  int local_var = -4;
  Base *obj = new DerivedDerived();

  divisor = 12;

  if (obj->cond(local_var) > 10) {
    exit(0);
  }

  result = wrapper(divisor);

  delete obj;
}
