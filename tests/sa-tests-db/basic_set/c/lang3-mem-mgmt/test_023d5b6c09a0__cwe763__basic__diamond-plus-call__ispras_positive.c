// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Память освобождается с помощью указателя, указывающего не на начало
// выделенного блока.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int ret_func(int param1) { return param1; }

void func(int param) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  int func_res = ret_func(10);

  if (param + func_res > 48) {
    pointer1 = (int *)malloc(12 * sizeof(int));
    pointer2 = pointer1 + 6;
  }

  if (param + func_res > 48) {
    free(pointer2); // FLAW
  }
}
