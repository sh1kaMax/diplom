// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdio.h>
#include <stdlib.h>

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int *pointer = NULL, quantity = 13;

  std::vector<int> vec(12, 0);

  int local_var1 = 45;
  int local_var2 = 134;
  int index1 = 1;
  int index2 = 8;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    scanf("%d", &quantity);
  }

  if (local_var1 == vec[8]) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}
