// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

int *pointer = NULL;

class ExceptionClass {};

void func(void) {
  int freed_flag = 0;

  try {
    free(pointer);
    throw ExceptionClass();
    pointer = (int *)malloc(17 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  } catch (const ExceptionClass &excpt) {
  }
}
