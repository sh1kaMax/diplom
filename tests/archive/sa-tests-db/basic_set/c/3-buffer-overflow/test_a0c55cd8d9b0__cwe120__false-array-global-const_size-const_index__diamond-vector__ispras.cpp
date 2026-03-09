// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-const_index.json
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

int buffer[39];

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int result = 0;
  unsigned int index = 0;

  std::vector<int> vec(23, 0);

  int local_var1 = 22;
  int local_var2 = 96;
  int index1 = 7;
  int index2 = 14;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 39;
  }

  if (local_var1 == vec[14]) {
    result = buffer[index];
  }

  return;
}
