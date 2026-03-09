// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-const_size-func-access-with-index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которую передаётся
// массив по указателю. Индекс является константой.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int get_buffer_elem(int *buf_ptr_par, int buf_index_par) {
  return buf_ptr_par[buf_index_par];
}

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int buffer[37];
  int result = 0;
  unsigned int index = 0;

  std::vector<int> vec(21, 0);

  int local_var1 = 78;
  int local_var2 = 168;
  int index1 = 4;
  int index2 = 8;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    index = 37;
  }

  if (local_var1 == vec[4]) {
    result = get_buffer_elem(buffer, index); // FLAW
  }

  return;
}
