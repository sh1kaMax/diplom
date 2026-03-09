// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 61, divisor = 6, result;

  std::vector<int> vec(42, 0);

  int local_var1 = 6;
  int local_var2 = 103;
  int index1 = 3;
  int index2 = 37;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = wrapper(48);
  }

  if (local_var1 == vec[37]) {
    result = divident / divisor;
  }
}
