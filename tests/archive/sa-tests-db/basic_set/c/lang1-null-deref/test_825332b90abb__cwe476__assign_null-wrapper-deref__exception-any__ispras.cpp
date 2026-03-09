// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель.
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

class ExceptionClass {};

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  try {
    pointer = NULL;
    throw ExceptionClass();
  } catch (...) {
    wrapper(pointer); // FLAW
  }
}
