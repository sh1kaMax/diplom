// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: pcall-int-value.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока. Вызов функции осуществляется по
// указателю.

#include <stdlib.h>

int model_external_func(int external_param);

int callee(int par1) {
  if (par1 > 89)
    return 20;

  return 10;
}

int func(void) {
  int result = 0;

  int local_var = 3;
  int (*func_ptr)(int) = &callee;

  int x;

  if (func_ptr(local_var) > 10) {
    exit(0);
  }

  result = model_external_func(x); // FLAW

  return result;
}
