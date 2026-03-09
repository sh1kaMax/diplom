// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: new-free.json
//
// Память выделяется с помощью оператора new
// Память освобождается с помощью стандартной функции free.
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
    if (par1 > 36)
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
  int *pointer = NULL;
  int freed_flag = 0;

  int local_var = -4;
  Base *obj = new Derived();

  pointer = new int(22);

  if (obj->cond(local_var) > 10) {
    exit(0);
  }

  free(pointer); // FLAW

  delete obj;
}
