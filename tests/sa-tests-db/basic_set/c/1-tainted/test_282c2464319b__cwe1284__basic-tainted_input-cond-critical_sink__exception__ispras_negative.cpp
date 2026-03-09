// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: basic-tainted_input-cond-critical_sink.json
//
// Количество получено от пользователя.
// Отсутствуют проверки выхода количества за пределы допустимых значений.
// Количество передаётся в функцию, которая вызывает malloc в зависимости от
// флага.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param, int func_flag) {
  if (func_flag < 0)
    return;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

class ExceptionClass {};

void func(void) {
  int quantity = 9;
  int template_flag = 78;

  try {
    critical_sink(quantity, template_flag);
    throw ExceptionClass();
    scanf("%d", &quantity);
  } catch (const ExceptionClass &excpt) {
  }
}
