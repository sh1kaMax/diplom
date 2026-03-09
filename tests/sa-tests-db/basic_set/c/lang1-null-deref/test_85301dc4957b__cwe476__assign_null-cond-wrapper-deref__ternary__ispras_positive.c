// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-cond-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр больше нуля.
//
// Поточный вариант: ternary.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними с помощью тернарного оператора, выполнение достигает стока в
// случае истинности проверки.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var;

  pointer = NULL;

  var = (pointer == NULL ? 1 : 0);

  if (var) {
    wrapper(pointer, 83); // FLAW
  }
}
