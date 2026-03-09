// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: malloc-delete.json
//
// Память выделяется с помощью стандартной функции malloc.
// Память освобождается с помощью оператора delete.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  try {
    pointer = (int *)malloc(11 * sizeof(int));
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    delete pointer; // FLAW
  }
}
