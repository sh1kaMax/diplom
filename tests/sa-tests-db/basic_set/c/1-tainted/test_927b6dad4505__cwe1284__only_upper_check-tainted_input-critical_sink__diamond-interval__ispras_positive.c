// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в специально помеченную небезопасную функцию.
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

void func(int param) {
  int quantity = 11;

  if (param > 10 && param < 27) {
    scanf("%d", &quantity);
    if (quantity > 11) {
      exit(0);
      ;
    }
  }

  if (param > 10 && param < 27) {
    critical_sink(quantity); // FLAW
  }
}
