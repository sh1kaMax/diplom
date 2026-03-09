// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: write.json
//
// Запись значения по неинициализированному указателю.
//
// Поточный вариант: switch-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

void func(int *input_ptr) {

  int var;

  int *x;

  var = 0;

  switch (var) {
  case 1:
    *x = -11;
    break;
  case 0:
    exit(0);
    break;
  }
}
