// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: write.json
//
// Запись значения по неинициализированному указателю.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

void func(int *input_ptr) {

  int var;

  int *x;

  var = 0;

  do {
    var++;
  } while (var < 10);

  *x = 93; // FLAW
}
