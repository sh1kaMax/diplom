// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
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
  int divident = 37, divisor = 8, result;
  int var_a = 169;
  int var_b = 169;

  std::vector<int> vec(20, 0);

  int local_var1 = 11;
  int local_var2 = 87;
  int index1 = 5;
  int index2 = 9;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = var_a - var_b;
  }

  if (local_var1 == vec[5]) {
    result = divident / divisor; // FLAW
  }
}
