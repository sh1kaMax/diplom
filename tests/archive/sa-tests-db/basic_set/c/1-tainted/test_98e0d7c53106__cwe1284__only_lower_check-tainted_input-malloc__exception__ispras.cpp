// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdio.h>
#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int *pointer = NULL, quantity = 8;

  try {
    pointer = (int *)malloc(quantity * sizeof(int));
    throw ExceptionClass();
    scanf("%d", &quantity);
    if (quantity <= 0) {
      exit(0);
      ;
    }
  } catch (const ExceptionClass &excpt) {
  }

  free(pointer);
}
