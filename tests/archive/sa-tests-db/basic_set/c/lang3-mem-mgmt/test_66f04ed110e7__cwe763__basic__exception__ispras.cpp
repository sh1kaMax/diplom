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
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  try {
    pointer1 = (int *)malloc(29 * sizeof(int));
    pointer2 = pointer1 + 16;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    free(pointer2); // FLAW
  }
}
