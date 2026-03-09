// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: false-assign_null-cond-inverted-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр меньше или равен нулю. В
// функцию передаётся положительное значение, поэтому ошибки не будет.
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par <= 0)
    *ptr = 1;
}

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var1 = 92;

  auto init = [&]() { local_var1 = 239; };

  if (local_var1 > 65) {
    pointer = NULL;
  }

  init();

  if (local_var1 == 239) {
    wrapper(pointer, 28);
  }
}
