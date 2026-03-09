// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 3; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int buffer[25];
  unsigned int index = 0;

  std::vector<int> vec(80, 0);

  int local_var1 = 96;
  int local_var2 = 118;
  int index1 = 10;
  int index2 = 62;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 25;
  }

  if (local_var1 == vec[62]) {
    index = index_change_func(index);
    result = buffer[index];
  }

  return;
}
