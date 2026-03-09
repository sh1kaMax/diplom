// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
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
  int divident = 66, divisor = 7, result;
  int var_a = 44;
  int var_b = 46;

  std::vector<int> vec(86, 0);

  int local_var1 = 62;
  int local_var2 = 119;
  int index1 = 8;
  int index2 = 75;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = var_a - var_b;
  }

  if (local_var1 == vec[75]) {
    result = divident / divisor;
  }
}
