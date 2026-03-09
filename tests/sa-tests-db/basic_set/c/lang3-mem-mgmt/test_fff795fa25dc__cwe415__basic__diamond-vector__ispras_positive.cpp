// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
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

  std::vector<int> vec(98, 0);

  int local_var1 = 22;
  int local_var2 = 44;
  int index1 = 32;
  int index2 = 36;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = (int *)malloc(28 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (local_var1 == vec[32]) {
    free(pointer); // FLAW
  }
}
