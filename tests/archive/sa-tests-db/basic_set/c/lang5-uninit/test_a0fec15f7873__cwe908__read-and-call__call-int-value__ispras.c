// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-int-value.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока

#include <stdlib.h>

void model_external_func(int external_param);

int callee(int par1) {
  if (par1 > 73)
    return 20;

  return 10;
}

int *func(void) {

  int local_var = -4;

  int *x = malloc(sizeof(int));

  if (callee(local_var) > 10) {
    exit(0);
  }

  if (x != NULL) {
    model_external_func(*x); // FLAW
  }

  return x;
}
