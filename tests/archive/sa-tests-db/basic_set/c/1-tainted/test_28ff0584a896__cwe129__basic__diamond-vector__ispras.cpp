// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdio.h>
#include <stdlib.h>

int store;

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  std::vector<int> vec(29, 0);

  int local_var1 = 35;
  int local_var2 = 73;
  int index1 = 13;
  int index2 = 19;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    scanf("%d", &index);
  }

  if (local_var1 == vec[19]) {
    store = array[index];
  }
}
