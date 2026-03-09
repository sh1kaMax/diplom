// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

void callee(int *pointer_param) { *pointer_param = 329; }

int func(int *param) {
  int template_flag;

  int var = 0;
  int other = 73;

  if (param == NULL) {
    template_flag = 60;
  }

  callee(&var);

  if (var < other) {
    exit(0);
  }

  memset(param, 0, sizeof(int)); // FLAW
  use_mem_to_keep_memset(param);

  return 0;
}
