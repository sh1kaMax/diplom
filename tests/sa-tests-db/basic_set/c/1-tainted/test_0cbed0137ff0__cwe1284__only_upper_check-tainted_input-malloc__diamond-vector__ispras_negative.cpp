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
  int *pointer = NULL, quantity = 14;

  std::vector<int> vec(70, 0);

  int local_var1 = 28;
  int local_var2 = 88;
  int index1 = 32;
  int index2 = 66;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    scanf("%d", &quantity);
    if (quantity > 14) {
      exit(0);
      ;
    }
  }

  if (local_var1 == vec[66]) {
    pointer = (int *)malloc(quantity * sizeof(int));
  }

  free(pointer);
}
