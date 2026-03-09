// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_func_input-critical_sink.json
//
// Количество получено от пользователя в вызываемой функции.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в функцию, которая вызывает malloc.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

int get_source() {
  int get_source_var;
  scanf("%d", &get_source_var);
  return get_source_var;
}

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int quantity = 19;

  std::vector<int> vec(80, 0);

  int local_var1 = 98;
  int local_var2 = 148;
  int index1 = 23;
  int index2 = 45;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    quantity = get_source();
  }

  if (local_var1 == vec[23]) {
    critical_sink(quantity); // FLAW
  }
}
