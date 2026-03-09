// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Память освобождается с помощью указателя, указывающего не на начало
// выделенного блока.
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
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  std::vector<int> vec(11, 0);

  int local_var1 = 25;
  int local_var2 = 124;
  int index1 = 2;
  int index2 = 10;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer1 = (int *)malloc(29 * sizeof(int));
    pointer2 = pointer1 + 7;
  }

  if (local_var1 == vec[2]) {
    free(pointer2); // FLAW
  }
}
