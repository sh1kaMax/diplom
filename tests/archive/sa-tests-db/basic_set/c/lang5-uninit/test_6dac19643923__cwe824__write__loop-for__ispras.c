// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: write.json
//
// Запись значения по неинициализированному указателю.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

void func(int *input_ptr) {

  int var;

  int *x;

  var = 0;

  for (var = 0; var < 14; var++)
    ;

  *x = 44; // FLAW
}
