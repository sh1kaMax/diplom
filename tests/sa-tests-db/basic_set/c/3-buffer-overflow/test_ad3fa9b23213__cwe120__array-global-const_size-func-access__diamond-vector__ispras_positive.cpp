// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int buffer[21];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int result = 0;
  unsigned int index = 0;

  std::vector<int> vec(98, 0);

  int local_var1 = 69;
  int local_var2 = 96;
  int index1 = 30;
  int index2 = 53;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 21;
  }

  if (local_var1 == vec[30]) {
    result = get_buffer_elem(index); // FLAW
  }

  return;
}
