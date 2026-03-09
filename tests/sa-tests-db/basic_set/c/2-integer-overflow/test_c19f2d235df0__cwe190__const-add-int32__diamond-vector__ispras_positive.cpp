// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int32.json
//
// Знаковое значение задается с помощью константы INT_MAX.
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
  int32_t data = 0;
  int32_t result;

  std::vector<int> vec(98, 0);

  int local_var1 = 22;
  int local_var2 = 44;
  int index1 = 32;
  int index2 = 36;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    data = INT_MAX;
  }

  if (local_var1 == vec[32]) {
    result = data + 1; // FLAW
  }
}
