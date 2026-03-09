// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int32.json
//
// Знаковое значение задается с помощью константы INT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: bool-compare-member.cpp
// Путь от источника до стока зависит от функции, которая сравнивает аргумент со
// значением члена класса.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

class SomeClass {
  int member_flag;

public:
  bool isTrue(int is_true_par);

  void setVal(int set_val_par);

  void func(void);
};

bool SomeClass::isTrue(int is_true_par) { return member_flag > is_true_par; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  int32_t data = 0;
  int32_t result;

  setVal(86);

  data = INT_MAX;

  setVal(101);

  if (isTrue(105)) {
    setVal(-8);

    result = data + 1;
  }
}
