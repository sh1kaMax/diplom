// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: new-array-delete.json
//
// Память выделяется с помощью оператора new
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

  std::vector<int> vec(14, 0);

  int local_var1 = 44;
  int local_var2 = 115;
  int index1 = 8;
  int index2 = 12;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = new int(15);
  }

  if (local_var1 == vec[8]) {
    delete[] pointer; // FLAW
  }
}
