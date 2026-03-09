// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-int32.json
//
// Знаковое значение задается с помощью константы INT_MIN.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int32_t data = 1;
  int32_t result;

  std::vector<int> vec(59, 0);

  int local_var1 = 50;
  int local_var2 = 69;
  int index1 = 10;
  int index2 = 51;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    data = INT_MIN;
  }

  if (local_var1 == vec[10]) {
    result = data - 1; // FLAW
  }
}
