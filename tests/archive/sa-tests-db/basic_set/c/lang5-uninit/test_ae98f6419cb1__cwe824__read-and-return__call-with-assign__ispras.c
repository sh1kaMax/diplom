// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-return.json
//
// Возврат значения неинициализированного указателя из функции.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 111; }

int *func(void) {
  int *result = NULL;

  int var = 0;

  int *x;

  callee(&var);

  if (var > 144) {
    exit(0);
  }

  result = x; // FLAW

  return result;
}
