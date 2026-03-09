// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
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
  int divident = 43, divisor = 7, result;

  setVal(40);

  divisor = 0;

  setVal(57);

  if (isTrue(56)) {
    setVal(-57);

    result = divident % divisor; // FLAW
  }
}
