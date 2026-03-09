// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_memset.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: call-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int callee(int par1) {
  if (par1 > 83)
    return 20;

  return 10;
}

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var = -5;

  pointer = NULL;

  if (callee(local_var) == 10) {
    exit(0);
  }

  memset(pointer, 0, sizeof(int));
  use_mem_to_keep_memset(pointer);
}
