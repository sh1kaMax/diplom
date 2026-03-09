// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: array-new-array-delete.json
//
// Память выделяется с помощью оператора new[]
// Память освобождается с помощью оператора delete[].
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

  std::vector<int> vec(34, 0);

  int local_var1 = 95;
  int local_var2 = 192;
  int index1 = 10;
  int index2 = 28;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = new int[10];
  }

  if (local_var1 == vec[10]) {
    delete[] pointer;
  }
}
