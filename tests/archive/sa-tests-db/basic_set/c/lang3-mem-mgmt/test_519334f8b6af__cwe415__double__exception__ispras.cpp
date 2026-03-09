// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  try {
    free(pointer1);
    free(pointer2);
    pointer1 = NULL;
    throw ExceptionClass();
    pointer1 = (int *)malloc(23 * sizeof(int));
    pointer2 = (int *)malloc(23 * sizeof(int));
    free(pointer2);
    freed_flag = 1;
  } catch (const ExceptionClass &excpt) {
  }

  free(pointer1);
}
