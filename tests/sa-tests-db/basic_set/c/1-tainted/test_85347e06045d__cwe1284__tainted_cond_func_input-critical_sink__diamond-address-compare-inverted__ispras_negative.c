// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_cond_func_input-critical_sink.json
//
// Количество получено от пользователя в вызываемой функции, если параметр не
// отрицательный. Отсутствуют проверки выхода количества за пределы допустимых
// значений. Количество передаётся в функцию, которая вызывает malloc.
//
// Поточный вариант: diamond-address-compare-inverted.c
// Недостижимый путь от источника до стока с проверками похожих условий, которые
// сравнивают адреса полей.

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

struct struct_type {
  int field1;
  int field2;
  int field3;
};

struct struct_type struct_glob;

void func(void) {
  int quantity = 8;
  int template_flag = 55;

  int *addr1 = &struct_glob.field1;
  int *addr2 = &struct_glob.field2;

  if (addr2 > addr1) {
    quantity = get_source(template_flag);
  }

  if (addr2 < addr1) {
    critical_sink(quantity);
  }
}
