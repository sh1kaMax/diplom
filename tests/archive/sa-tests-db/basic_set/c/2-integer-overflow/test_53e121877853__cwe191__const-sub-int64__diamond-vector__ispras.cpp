// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-int64.json
//
// Знаковое значение задается с помощью константы LLONG_MIN.
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
  int64_t data = 1;
  int64_t result;

  std::vector<int> vec(31, 0);

  int local_var1 = 86;
  int local_var2 = 151;
  int index1 = 9;
  int index2 = 18;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    data = LLONG_MIN;
  }

  if (local_var1 == vec[9]) {
    result = data - 1; // FLAW
  }
}
