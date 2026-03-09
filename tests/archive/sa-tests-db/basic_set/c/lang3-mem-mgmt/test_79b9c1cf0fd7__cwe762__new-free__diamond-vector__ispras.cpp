// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: new-free.json
//
// Память выделяется с помощью оператора new
// Память освобождается с помощью стандартной функции free.
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

  std::vector<int> vec(25, 0);

  int local_var1 = 94;
  int local_var2 = 168;
  int index1 = 10;
  int index2 = 23;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = new int(12);
  }

  if (local_var1 == vec[10]) {
    free(pointer); // FLAW
  }
}
