// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
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
  int freed_flag = 0;

  std::vector<int> vec(90, 0);

  int local_var1 = 38;
  int local_var2 = 63;
  int index1 = 51;
  int index2 = 83;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer1 = (int *)malloc(15 * sizeof(int));
    pointer2 = (int *)malloc(15 * sizeof(int));
    free(pointer2);
    freed_flag = 1;
  }

  if (local_var1 == vec[83]) {
    free(pointer1);
    free(pointer2);
    pointer1 = NULL;
  }

  free(pointer1);
}
