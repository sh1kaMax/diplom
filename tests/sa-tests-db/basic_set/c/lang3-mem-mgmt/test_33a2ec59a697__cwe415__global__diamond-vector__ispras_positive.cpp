// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int *pointer = NULL;

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int freed_flag = 0;

  std::vector<int> vec(88, 0);

  int local_var1 = 38;
  int local_var2 = 66;
  int index1 = 38;
  int index2 = 82;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = (int *)malloc(23 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (local_var1 == vec[38]) {
    free(pointer); // FLAW
  }
}
