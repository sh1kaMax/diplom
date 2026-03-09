// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
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
  int *pointer = NULL, quantity = 9;

  std::vector<int> vec(73, 0);

  int local_var1 = 53;
  int local_var2 = 114;
  int index1 = 32;
  int index2 = 54;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    scanf("%d", &quantity);
    if (quantity > 9) {
      exit(0);
      ;
    }
  }

  if (local_var1 == vec[32]) {
    pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
  }

  free(pointer);
}
