// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: setter-getter.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает bool
// значение, зависящее от члена класса. Есть setter, который это значение
// выставляет.

#include <stdio.h>
#include <stdlib.h>

class SomeClass {
  int member_flag;

public:
  bool isTrue();

  void setVal(int set_val_par);

  void func(void);
};

bool SomeClass::isTrue() { return member_flag > 14; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  int divident = 54, divisor = 9, result;

  setVal(7);

  scanf("%d", &divisor);

  setVal(32);

  if (isTrue()) {
    setVal(-5);

    result = divident / divisor; // FLAW
  }
}
