// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Память освобождается с помощью указателя, указывающего не на начало
// выделенного блока.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  try {
    free(pointer2);
    throw ExceptionClass();
    pointer1 = (int *)malloc(30 * sizeof(int));
    pointer2 = pointer1 + 5;
  } catch (const ExceptionClass &excpt) {
  }
}
