// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в специально помеченную небезопасную функцию.
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

void func(int param) {
  int quantity = 20;

  if (param > 14 && param < 53) {
    scanf("%d", &quantity);
    if (quantity > 20) {
      exit(0);
      ;
    }
  }

  if (param > 48 && param < 52) {
    critical_sink(quantity); // FLAW
  }
}
