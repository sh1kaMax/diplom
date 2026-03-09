// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: call-pointer-alias.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой сначала сохраняется в локальную
// переменную-указатель, а затем с его помощью передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение нулевое,
// поэтому проверка в вызывающей функции неуспешна и выполнение достигает стока

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int callee(int *pointer_param) {
  if (*pointer_param > 0)
    return 1;
  else
    return 0;
}

int func(int *param) {
  int template_flag;

  int local_var = 0, *local_pointer = &local_var;

  if (param == NULL) {
    template_flag = 18;
  }

  if (callee(local_pointer)) {
    exit(0);
  }

  memset(param, 0, sizeof(int)); // FLAW
  use_mem_to_keep_memset(param);

  return 0;
}
