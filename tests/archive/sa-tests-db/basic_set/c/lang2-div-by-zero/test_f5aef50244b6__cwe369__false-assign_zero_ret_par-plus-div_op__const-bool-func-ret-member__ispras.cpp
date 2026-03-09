// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero_ret_par-plus-div_op.json
//
// Ненулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: const-bool-func-ret-member.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// значение члена класса. Значение устанавливается вначале в false, затем в
// true.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

class SomeClass {
  bool member_flag;

public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return member_flag; }

void SomeClass::func(void) {
  int divident = 64, divisor = 8, result;

  member_flag = false;

  divisor = wrapper(46);
  divisor -= 36;

  member_flag = true;

  if (isTrue()) {
    result = divident / divisor;
  }
}
