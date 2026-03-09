// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_memset.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

class ExceptionClass {};

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  try {
    memset(pointer, 0, sizeof(int));
    use_mem_to_keep_memset(pointer);
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    pointer = NULL;
  }
}
