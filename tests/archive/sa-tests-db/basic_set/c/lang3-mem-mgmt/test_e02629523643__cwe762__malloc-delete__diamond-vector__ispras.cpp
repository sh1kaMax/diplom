// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: malloc-delete.json
//
// Память выделяется с помощью стандартной функции malloc.
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

  std::vector<int> vec(74, 0);

  int local_var1 = 13;
  int local_var2 = 82;
  int index1 = 25;
  int index2 = 29;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = (int *)malloc(11 * sizeof(int));
  }

  if (local_var1 == vec[25]) {
    delete pointer; // FLAW
  }
}
