// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_cond_func_input-critical_sink.json
//
// Количество получено от пользователя в вызываемой функции, если параметр не
// отрицательный. Отсутствуют проверки выхода количества за пределы допустимых
// значений. Количество передаётся в функцию, которая вызывает malloc.
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

int get_source(int flag_param) {
  ;
  if (flag_param < 0)
    return 1;
  int get_source_var;
  scanf("%d", &get_source_var);
  return get_source_var;
}

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int quantity = 12;
  int template_flag = 2;

  std::vector<int> vec(52, 0);

  int local_var1 = 17;
  int local_var2 = 23;
  int index1 = 24;
  int index2 = 39;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    quantity = get_source(template_flag);
  }

  if (local_var1 == vec[39]) {
    critical_sink(quantity);
  }
}
