// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int *pointer = NULL;

class ExceptionClass {};

void func(void) {
  int freed_flag = 0;

  try {
    pointer = (int *)malloc(12 * sizeof(int));
    free(pointer);
    freed_flag = 1;
    throw ExceptionClass();
  } catch (...) {
    free(pointer); // FLAW
  }
}
