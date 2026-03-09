// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: auto.json
//
// Память выделяется в автоматической памяти (на стеке).
// Адрес выделенной памяти сохраняется в локальной переменной.
// Память освобождается с помощью указателя, не указывающего на кучу.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int ret_func(int param1) { return param1; }

void func(int param) {
  int array[50];
  int *pointer = NULL;

  int func_res = ret_func(10);

  if (param + func_res > 40) {
    pointer = array;
  }

  if (param + func_res > 40) {
    free(pointer); // FLAW
  }
}
