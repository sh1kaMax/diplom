// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-const_index-from-func.json
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

int index_change_func(int func_par) { return func_par + 6; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int buffer[39];
  unsigned int index = 0;

  std::vector<int> vec(55, 0);

  int local_var1 = 88;
  int local_var2 = 173;
  int index1 = 33;
  int index2 = 34;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 39;
  }

  if (local_var1 == vec[33]) {
    index = index_change_func(index);
    result = buffer[index]; // FLAW
  }

  return;
}
