// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-static-const_size-const_index-direct_ref.json
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
int buffer[40];

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  unsigned int index = 0;

  std::vector<int> vec(38, 0);

  int local_var1 = 57;
  int local_var2 = 101;
  int index1 = 19;
  int index2 = 32;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 40;
  }

  if (local_var1 == vec[19]) {
    result = buffer[index]; // FLAW
  }

  return;
}
