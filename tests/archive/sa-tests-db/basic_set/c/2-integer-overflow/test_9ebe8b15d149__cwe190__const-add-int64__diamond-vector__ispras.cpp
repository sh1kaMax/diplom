// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int64.json
//
// Знаковое значение задается с помощью константы LLONG_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
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
  int64_t data = 0;
  int64_t result;

  std::vector<int> vec(91, 0);

  int local_var1 = 57;
  int local_var2 = 70;
  int index1 = 75;
  int index2 = 85;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    data = LLONG_MAX;
  }

  if (local_var1 == vec[85]) {
    result = data + 1;
  }
}
