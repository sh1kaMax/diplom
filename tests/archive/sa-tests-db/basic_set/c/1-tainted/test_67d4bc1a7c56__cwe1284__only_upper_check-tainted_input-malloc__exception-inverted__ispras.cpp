// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: only_upper_check-tainted_input-malloc.json
//
// Количество получено от пользователя.
// Отсутствует проверка выхода количества за левую границу интервала допустимых
// значений. Количество передаётся в стандартную функцию malloc.
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdio.h>
#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int *pointer = NULL, quantity = 10;

  try {
    pointer = (int *)malloc(quantity * sizeof(int));
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    scanf("%d", &quantity);
    if (quantity > 10) {
      exit(0);
      ;
    }
  }

  free(pointer);
}
