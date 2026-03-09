// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-static-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>
#include <string.h>

int result = 0;
int buffer[34];
void use_mem_to_keep_memset(int *);

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  unsigned int index = 0;

  std::vector<int> vec(91, 0);

  int local_var1 = 64;
  int local_var2 = 110;
  int index1 = 71;
  int index2 = 86;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 34 + 1;
  }

  if (local_var1 == vec[71]) {
    memset(buffer, 0, index * sizeof(int)); // FLAW
    use_mem_to_keep_memset(buffer);
  }

  return;
}
