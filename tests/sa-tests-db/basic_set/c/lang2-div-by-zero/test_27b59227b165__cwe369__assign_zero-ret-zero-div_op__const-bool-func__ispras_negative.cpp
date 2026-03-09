// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: const-bool-func.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает
// false.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

class SomeClass {
public:
  bool isTrue();

  void func(void);
};

bool SomeClass::isTrue() { return false; }

void SomeClass::func(void) {
  int divident = 67, divisor = 5, result;

  divisor = wrapper(68);

  if (isTrue()) {
    result = divident / divisor;
  }
}
