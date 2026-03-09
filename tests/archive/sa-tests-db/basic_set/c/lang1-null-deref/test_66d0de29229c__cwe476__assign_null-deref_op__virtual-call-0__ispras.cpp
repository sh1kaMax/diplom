// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_op.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
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
    if (par1 > 12)
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
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var = 0;
  Base *obj = new DerivedSecond();

  pointer = NULL;

  if (obj->cond(local_var) > 10) {
    exit(0);
  }

  *pointer = 0;

  delete obj;
}
