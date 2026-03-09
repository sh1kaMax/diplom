// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_cond_func_input-critical_sink.json
//
// Количество получено от пользователя в вызываемой функции, если параметр не
// отрицательный. Отсутствуют проверки выхода количества за пределы допустимых
// значений. Количество передаётся в функцию, которая вызывает malloc.
//
// Поточный вариант: bool-compare-member.cpp
// Путь от источника до стока зависит от функции, которая сравнивает аргумент со
// значением члена класса.

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
  int member_flag;

public:
  bool isTrue(int is_true_par);

  void setVal(int set_val_par);

  void func(void);
};

bool SomeClass::isTrue(int is_true_par) { return member_flag > is_true_par; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  int quantity = 17;
  int template_flag = 36;

  setVal(45);

  quantity = get_source(template_flag);

  setVal(58);

  if (isTrue(66)) {
    setVal(-13);

    critical_sink(quantity);
  }
}
