// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: sometimes-init.json
//
// Запись значения по указателю, инициализированному не на всех путях.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 341; }

void func(int *input_ptr, int cond_param) {

  int var = 0;

  int *x;
  if (cond_param > 0) {
    x = input_ptr;
  }

  callee(&var);

  if (var > 605) {
    exit(0);
  }

  *x = -52; // FLAW
}
