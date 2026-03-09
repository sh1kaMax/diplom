// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
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

int *func(void) {

  int local_var = 77;

  int *x = malloc(sizeof(int));

  if (callee(local_var, 155) > 0) {
    exit(0);
  }

  if (x != NULL && *x < 0) { // FLAW
    *x = 0;
  }

  return x;
}
