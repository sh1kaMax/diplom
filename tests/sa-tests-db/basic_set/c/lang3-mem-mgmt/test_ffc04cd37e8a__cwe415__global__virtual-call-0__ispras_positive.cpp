// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: virtual-call-0.cpp
// Путь от источника до стока зависит от возвращаемого значения метода,
// вызванного косвенно как метод базового класса

#include <stdlib.h>

int *pointer = NULL;

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
    if (par1 > 83)
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
  int freed_flag = 0;

  int local_var = -5;
  Base *obj = new Derived();

  pointer = (int *)malloc(14 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (obj->cond(local_var) > 10) {
    exit(0);
  }

  free(pointer); // FLAW

  delete obj;
}
