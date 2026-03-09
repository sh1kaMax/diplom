// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  try {
    free(pointer);
    throw ExceptionClass();
    pointer = (int *)malloc(24 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  } catch (const ExceptionClass &excpt) {
  }
}
