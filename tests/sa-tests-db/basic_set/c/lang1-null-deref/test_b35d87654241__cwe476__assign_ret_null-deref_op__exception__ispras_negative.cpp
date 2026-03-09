// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

class ExceptionClass {};

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  try {
    *pointer = 0;
    throw ExceptionClass();
    pointer = null_func(65);
  } catch (const ExceptionClass &excpt) {
  }
}
