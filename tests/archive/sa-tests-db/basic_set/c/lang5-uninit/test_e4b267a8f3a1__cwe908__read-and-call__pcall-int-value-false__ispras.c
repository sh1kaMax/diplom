// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: pcall-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается. Вызов функции осуществляется с помощью
// указателя.

#include <stdlib.h>

void model_external_func(int external_param);

int callee(int par1) {
  if (par1 > 84)
    return 20;

  return 10;
}

int *func(void) {

  int local_var = -4;
  int (*func_ptr)(int) = &callee;

  int *x = malloc(sizeof(int));

  if (func_ptr(local_var) == 10) {
    exit(0);
  }

  if (x != NULL) {
    model_external_func(*x);
  }

  return x;
}
