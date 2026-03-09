// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-static-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
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
int buffer[26];

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  unsigned int index = 0;

  std::vector<int> vec(83, 0);

  int local_var1 = 53;
  int local_var2 = 84;
  int index1 = 28;
  int index2 = 67;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 26;
  }

  if (local_var1 == vec[67]) {
    result = buffer[index];
  }

  return;
}
