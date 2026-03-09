// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
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
    if (par1 > 73)
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
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int local_var = 2;
  Base *obj = new DerivedSecond();

  pointer1 = (int *)malloc(16 * sizeof(int));
  pointer2 = (int *)malloc(16 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  if (obj->cond(local_var) > 10) {
    exit(0);
  }

  free(pointer1);
  free(pointer2);
  pointer1 = NULL;

  delete obj;

  free(pointer1);
}
