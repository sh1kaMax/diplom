// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint32.json
//
// Беззнаковое значение задается с помощью константы UINT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: virtual-call-0.cpp
// Путь от источника до стока зависит от возвращаемого значения метода,
// вызванного косвенно как метод базового класса

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
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
    if (par1 > 40)
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
  uint32_t data = 0;
  uint32_t result;

  int local_var = 5;
  Base *obj = new Derived();

  data = UINT_MAX;

  if (obj->cond(local_var) > 10) {
    exit(0);
  }

  result = data + 1; // FLAW

  delete obj;
}
