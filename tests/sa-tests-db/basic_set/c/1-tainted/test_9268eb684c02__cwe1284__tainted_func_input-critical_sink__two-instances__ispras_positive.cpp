// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_func_input-critical_sink.json
//
// Количество получено от пользователя в вызываемой функции.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в функцию, которая вызывает malloc.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

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
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int quantity = 19;

  SomeClass *cl_var1 = new SomeClass(79);
  SomeClass *cl_var2 = new SomeClass(-88);

  quantity = get_source();

  if (cl_var1->getVal() > 76) {
    critical_sink(quantity); // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
