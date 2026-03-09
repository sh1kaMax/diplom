// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в специально помеченную небезопасную функцию.
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

struct struct_type {
  int field1;
  int field2;
  int field3;
};

struct struct_type struct_glob;

void func(void) {
  int quantity = 20;

  int *addr1 = &struct_glob.field1;
  int *addr2 = &struct_glob.field2;

  if (addr2 > addr1) {
    scanf("%d", &quantity);
    if (quantity <= 0) {
      exit(0);
      ;
    }
  }

  if (addr1 < addr2) {
    critical_sink(quantity); // FLAW
  }
}
