// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: sometimes-init.json
//
// Запись значения по указателю, инициализированному не на всех путях.
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdlib.h>

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

void func(int *input_ptr, int cond_param) {

  int local_var = 26;

  int *x;
  if (cond_param > 0) {
    x = input_ptr;
  }

  if (callee(local_var, 187) > 0) {
    exit(0);
  }

  *x = 65; // FLAW
}
