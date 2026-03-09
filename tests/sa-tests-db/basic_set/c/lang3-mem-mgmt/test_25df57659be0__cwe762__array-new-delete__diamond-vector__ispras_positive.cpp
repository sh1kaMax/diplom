// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: array-new-delete.json
//
// Память выделяется с помощью оператора new[]
// Память освобождается с помощью оператора delete.
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
  int *pointer = NULL;
  int freed_flag = 0;

  std::vector<int> vec(63, 0);

  int local_var1 = 5;
  int local_var2 = 93;
  int index1 = 7;
  int index2 = 31;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = new int[26];
  }

  if (local_var1 == vec[7]) {
    delete pointer; // FLAW
  }
}
