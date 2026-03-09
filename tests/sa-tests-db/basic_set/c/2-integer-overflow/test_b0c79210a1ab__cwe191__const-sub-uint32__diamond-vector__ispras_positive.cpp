// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-uint32.json
//
// Беззнаковое значение задается с помощью константы 0.
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
  uint32_t data = 1;
  uint32_t result;

  std::vector<int> vec(60, 0);

  int local_var1 = 21;
  int local_var2 = 34;
  int index1 = 29;
  int index2 = 50;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    data = 0;
  }

  if (local_var1 == vec[29]) {
    result = data - 1; // FLAW
  }
}
