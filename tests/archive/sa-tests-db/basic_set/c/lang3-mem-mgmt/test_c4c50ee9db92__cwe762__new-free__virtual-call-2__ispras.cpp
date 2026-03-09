// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: new-free.json
//
// Память выделяется с помощью оператора new
// Память освобождается с помощью стандартной функции free.
//
// Поточный вариант: virtual-call-2.cpp
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
    if (par1 > 48)
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
  int *pointer = NULL;
  int freed_flag = 0;

  int local_var = 2;
  const Base &obj = DerivedDerived();

  pointer = new int(15);

  if (obj.cond(local_var) > 10) {
    exit(0);
  }

  free(pointer); // FLAW
}