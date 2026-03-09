// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: write-static.json
//
// Запись значения по неинициализированному статическому указателю.
// Запись не производится, так как значение неинициализированного глобального
// указателя равно нулю.
//
// Поточный вариант: switch-default-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdlib.h>

void func(int *input_ptr) {

  int var;

  static int *x;

  var = 0;

  switch (var) {
  default:
    if (x != NULL) {
      *x = 38;
    }
    break;
  case 0:
    exit(0);
    break;
  }
}
