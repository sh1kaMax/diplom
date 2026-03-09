// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в специально помеченную небезопасную функцию.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

void func(int param) {
  int quantity = 13;

  int arr[100];
  int some_var = 39;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[97] = 7;

  if (some_var) {
    scanf("%d", &quantity);
    if (quantity <= 0) {
      exit(0);
      ;
    }
  }

  if (arr[param]) {
    critical_sink(quantity); // FLAW
  }
}
