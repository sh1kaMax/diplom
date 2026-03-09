// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int result = 0;

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int *buffer = (int *)malloc(38 * sizeof(int));
  unsigned int index = 0;

  std::vector<int> vec(47, 0);

  int local_var1 = 35;
  int local_var2 = 108;
  int index1 = 23;
  int index2 = 44;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 38;
  }

  if (local_var1 == vec[44]) {
    result = buffer[index];
  }

  free(buffer);
  return;
}
