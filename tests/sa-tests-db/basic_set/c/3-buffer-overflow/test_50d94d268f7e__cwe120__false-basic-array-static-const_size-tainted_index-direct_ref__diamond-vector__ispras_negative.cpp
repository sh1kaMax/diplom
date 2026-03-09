// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-static-const_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdio.h>

int buffer[25];

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int result = 0;
  unsigned int index = 0;

  std::vector<int> vec(82, 0);

  int local_var1 = 5;
  int local_var2 = 92;
  int index1 = 51;
  int index2 = 71;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    scanf("%u", &index);
  }

  if (local_var1 == vec[71]) {
    result = buffer[index];
  }

  return;
}
