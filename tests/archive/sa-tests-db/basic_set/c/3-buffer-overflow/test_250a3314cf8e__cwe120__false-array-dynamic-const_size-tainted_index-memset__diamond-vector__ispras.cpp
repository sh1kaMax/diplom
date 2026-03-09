// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-dynamic-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int *buffer = (int *)malloc(22 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  std::vector<int> vec(35, 0);

  int local_var1 = 43;
  int local_var2 = 127;
  int index1 = 25;
  int index2 = 28;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    scanf("%u", &index);
  }

  if (local_var1 == vec[28]) {
    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
  }

  free(buffer);
  return;
}
