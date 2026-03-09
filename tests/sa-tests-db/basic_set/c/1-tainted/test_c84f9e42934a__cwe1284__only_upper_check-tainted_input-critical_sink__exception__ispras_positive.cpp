// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в специально помеченную небезопасную функцию.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

class ExceptionClass {};

void func(void) {
  int quantity = 16;

  try {
    scanf("%d", &quantity);
    if (quantity > 16) {
      exit(0);
      ;
    }
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    critical_sink(quantity); // FLAW
  }
}
