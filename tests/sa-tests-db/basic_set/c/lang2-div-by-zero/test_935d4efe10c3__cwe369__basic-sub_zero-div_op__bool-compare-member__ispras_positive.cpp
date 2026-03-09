// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: bool-compare-member.cpp
// Путь от источника до стока зависит от функции, которая сравнивает аргумент со
// значением члена класса.

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
  int divident = 22, divisor = 6, result;
  int var_a = 24;
  int var_b = 24;

  setVal(55);

  divisor = var_a - var_b;

  setVal(68);

  if (isTrue(64)) {
    setVal(54);

    result = divident / divisor; // FLAW
  }
}
