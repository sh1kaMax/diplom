// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_lower_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за правую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdio.h>
#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int *pointer = NULL, quantity = 8;

  try {
    scanf("%d", &quantity);
    if (quantity <= 0) {
      exit(0);
      ;
    }
    throw ExceptionClass();
  } catch (...) {
    pointer = (int *)malloc(quantity * sizeof(int)); // FLAW
  }

  free(pointer);
}
