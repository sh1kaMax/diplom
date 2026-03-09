// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-auto-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
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
  int buffer[21];
  unsigned int index = 0;

  std::vector<int> vec(17, 0);

  int local_var1 = 21;
  int local_var2 = 91;
  int index1 = 7;
  int index2 = 11;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 21;
  }

  if (local_var1 == vec[7]) {
    result = buffer[index]; // FLAW
  }

  return;
}
