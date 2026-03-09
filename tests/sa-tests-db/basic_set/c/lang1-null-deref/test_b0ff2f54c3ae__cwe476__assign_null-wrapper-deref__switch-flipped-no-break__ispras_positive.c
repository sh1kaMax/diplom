// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var;

  pointer = NULL;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    wrapper(pointer); // FLAW
    break;
  }
}
