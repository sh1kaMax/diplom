// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 190;
}

int func(int *param) {
  int template_flag;

  int var = 0;

  if (param == NULL) {
    template_flag = 75;
  }

  callee(&var, 6);

  if (var > 772) {
    exit(0);
  }

  memset(param, 0, sizeof(int)); // FLAW
  use_mem_to_keep_memset(param);

  return 0;
}
