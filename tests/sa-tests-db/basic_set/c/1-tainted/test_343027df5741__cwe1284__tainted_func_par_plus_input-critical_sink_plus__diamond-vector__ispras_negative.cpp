// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_func_par_plus_input-critical_sink_plus.json
//
// Количество получено от пользователя и присваивается в переменную через вызов
// функции, возвращающую сумму константы со своим аргументом. Отсутствуют
// проверки выхода количества за пределы допустимых значений. Количество
// передаётся в функцию, которая вызывает malloc, передавая в качестве параметра
// сумму аргумента и константы.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param + 10);
  malloc_res[0] = 0;
  free(malloc_res);
}

int get_source(int get_source_param) {
  ;
  return get_source_param + 15;
}

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int quantity = 180;
  int template_local_var;

  std::vector<int> vec(64, 0);

  int local_var1 = 84;
  int local_var2 = 141;
  int index1 = 53;
  int index2 = 58;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    scanf("%d", &template_local_var);
    quantity = get_source(template_local_var);
  }

  if (local_var1 == vec[58]) {
    critical_sink(quantity);
  }
}
