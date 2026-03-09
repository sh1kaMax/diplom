// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в специально помеченную небезопасную функцию.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int quantity = 17;

  std::vector<int> vec(87, 0);

  int local_var1 = 92;
  int local_var2 = 192;
  int index1 = 57;
  int index2 = 80;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    scanf("%d", &quantity);
    if (quantity > 17) {
      exit(0);
      ;
    }
  }

  if (local_var1 == vec[57]) {
    critical_sink(quantity); // FLAW
  }
}
