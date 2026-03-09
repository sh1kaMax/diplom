// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  float divident = 37.11, divisor = 25.84, result;

  std::vector<int> vec(59, 0);

  int local_var1 = 100;
  int local_var2 = 110;
  int index1 = 37;
  int index2 = 42;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = 0.0;
  }

  if (local_var1 == vec[42]) {
    result = divident / divisor;
  }
}
