// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: virtual-call-3.cpp
// Путь от источника до стока зависит от возвращаемого значения метода,
// вызванного косвенно как метод базового класса

#include <stdio.h>
#include <stdlib.h>

int store;

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
    if (par1 > 62)
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
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  int local_var = -1;
  const Base &obj = Derived();

  scanf("%d", &index);

  if (obj.cond(local_var) > 10) {
    exit(0);
  }

  store = array[index]; // FLAW
}