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
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par <= 0)
    *ptr = 1;
}

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var;

  pointer = NULL;

  var = (pointer == NULL ? 0 : 1);

  if (var) {
    wrapper(pointer, 69);
  }
}
