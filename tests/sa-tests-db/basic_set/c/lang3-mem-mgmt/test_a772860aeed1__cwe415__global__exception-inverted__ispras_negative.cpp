// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int *pointer = NULL;

class ExceptionClass {};

void func(void) {
  int freed_flag = 0;

  try {
    free(pointer);
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    pointer = (int *)malloc(21 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }
}
