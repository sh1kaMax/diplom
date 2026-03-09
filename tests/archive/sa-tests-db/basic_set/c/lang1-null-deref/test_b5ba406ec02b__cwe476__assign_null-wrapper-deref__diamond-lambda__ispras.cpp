// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var1 = 79;

  auto init = [&]() { local_var1 = 182; };

  if (local_var1 < 182) {
    pointer = NULL;
  }

  init();

  if (local_var1 < 182) {
    wrapper(pointer);
  }
}
