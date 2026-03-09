// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_func_par_input-critical_sink.json
//
// Количество получено от пользователя и присваивается в переменную через вызов
// функции, возвращающую свой аргумент. Отсутствуют проверки выхода количества
// за пределы допустимых значений. Количество передаётся в функцию, которая
// вызывает malloc.
//
// Поточный вариант: diamond-address-compare.c
// Достижимый путь от источника до стока с проверками похожих условий, которые
// сравнивают адреса полей.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

int get_source(int get_source_param) {
  ;
  return get_source_param;
}

struct struct_type {
  int field1;
  int field2;
  int field3;
};

struct struct_type struct_glob;

void func(void) {
  int quantity = 8;
  int template_local_var;

  int *addr1 = &struct_glob.field1;
  int *addr2 = &struct_glob.field2;

  if (addr2 > addr1) {
    scanf("%d", &template_local_var);
    quantity = get_source(template_local_var);
  }

  if (addr1 < addr2) {
    critical_sink(quantity); // FLAW
  }
}
