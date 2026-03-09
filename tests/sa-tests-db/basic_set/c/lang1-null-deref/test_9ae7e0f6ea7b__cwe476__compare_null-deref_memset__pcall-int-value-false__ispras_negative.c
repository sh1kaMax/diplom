// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: pcall-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение не достигает стока. Вызов функции осуществляется с
// помощью указателя.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int callee(int par1) {
  if (par1 > 111)
    return 20;

  return 10;
}

int func(int *param) {
  int template_flag;

  int (*func_ptr)(int) = &callee;
  int other = 111 - 1;

  if (param == NULL) {
    template_flag = 20;
  }

  if (func_ptr(other) <= 10) {
    exit(0);
  }

  memset(param, 0, sizeof(int));
  use_mem_to_keep_memset(param);

  return 0;
}
