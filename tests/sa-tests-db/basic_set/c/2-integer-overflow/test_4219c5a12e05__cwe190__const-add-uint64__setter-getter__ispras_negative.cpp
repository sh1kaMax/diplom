// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint64.json
//
// Беззнаковое значение задается с помощью константы ULLONG_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: setter-getter.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает bool
// значение, зависящее от члена класса. Есть setter, который это значение
// выставляет.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

class SomeClass {
  int member_flag;

public:
  bool isTrue();

  void setVal(int set_val_par);

  void func(void);
};

bool SomeClass::isTrue() { return member_flag > 18; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  uint64_t data = 0;
  uint64_t result;

  setVal(3);

  data = ULLONG_MAX;

  setVal(11);

  if (isTrue()) {
    setVal(-1);

    result = data + 1;
  }
}
