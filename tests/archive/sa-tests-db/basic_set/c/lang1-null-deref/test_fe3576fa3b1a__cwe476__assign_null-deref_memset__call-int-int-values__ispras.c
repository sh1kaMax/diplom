// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_memset.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var = 5;

  pointer = NULL;

  if (callee(local_var, 184) > 0) {
    exit(0);
  }

  memset(pointer, 0, sizeof(int)); // FLAW
  use_mem_to_keep_memset(pointer);
}
