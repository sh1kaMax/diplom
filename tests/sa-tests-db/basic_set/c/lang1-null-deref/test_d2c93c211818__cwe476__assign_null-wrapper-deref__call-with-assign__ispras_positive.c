// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

void callee(int *pointer_param) { *pointer_param = 226; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var = 0;

  pointer = NULL;

  callee(&var);

  if (var > 782) {
    exit(0);
  }

  wrapper(pointer); // FLAW
}
