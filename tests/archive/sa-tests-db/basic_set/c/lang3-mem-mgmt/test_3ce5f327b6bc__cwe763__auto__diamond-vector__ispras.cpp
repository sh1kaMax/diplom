// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: auto.json
//
// Память выделяется в автоматической памяти (на стеке).
// Адрес выделенной памяти сохраняется в локальной переменной.
// Память освобождается с помощью указателя, не указывающего на кучу.
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
  int array[43];
  int *pointer = NULL;

  std::vector<int> vec(28, 0);

  int local_var1 = 69;
  int local_var2 = 120;
  int index1 = 15;
  int index2 = 18;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = array;
  }

  if (local_var1 == vec[15]) {
    free(pointer); // FLAW
  }
}
