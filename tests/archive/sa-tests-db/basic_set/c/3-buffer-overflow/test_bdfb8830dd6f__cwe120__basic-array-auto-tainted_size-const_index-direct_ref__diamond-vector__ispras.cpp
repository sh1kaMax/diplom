// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-auto-tainted_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdio.h>

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  unsigned int size;
  scanf("%u", &size);
  int buffer[size];
  int result = 0;
  unsigned int index = 0;

  std::vector<int> vec(63, 0);

  int local_var1 = 53;
  int local_var2 = 121;
  int index1 = 17;
  int index2 = 50;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 33;
  }

  if (local_var1 == vec[17]) {
    result = buffer[index]; // FLAW
  }

  return;
}
