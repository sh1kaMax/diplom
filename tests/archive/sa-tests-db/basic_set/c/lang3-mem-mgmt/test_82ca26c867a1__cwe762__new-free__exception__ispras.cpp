// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: new-free.json
//
// Память выделяется с помощью оператора new
// Память освобождается с помощью стандартной функции free.
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
    pointer = new int(16);
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    free(pointer); // FLAW
  }
}
