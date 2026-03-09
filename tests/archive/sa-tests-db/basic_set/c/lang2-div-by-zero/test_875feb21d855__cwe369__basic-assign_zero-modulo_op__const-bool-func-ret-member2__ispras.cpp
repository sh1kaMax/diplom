// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: const-bool-func-ret-member2.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// значение члена класса. Значение устанавливается вначале в false, затем в
// true. Но установка в true происходит после проверки. Поэтому путь недостижим.

#include <stdlib.h>

class SomeClass {
  bool member_flag;

public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return member_flag; }

void SomeClass::func(void) {
  int divident = 39, divisor = 3, result;

  member_flag = false;

  divisor = 0;

  if (isTrue()) {
    member_flag = true;
    result = divident % divisor;
  }
}
