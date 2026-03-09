// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_op.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
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
  int *pointer, other, dummy;
  pointer = &dummy;

  std::vector<int> vec(23, 0);

  int local_var1 = 32;
  int local_var2 = 75;
  int index1 = 1;
  int index2 = 6;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = NULL;
  }

  if (local_var1 == vec[1]) {
    *pointer = 0; // FLAW
  }
}
