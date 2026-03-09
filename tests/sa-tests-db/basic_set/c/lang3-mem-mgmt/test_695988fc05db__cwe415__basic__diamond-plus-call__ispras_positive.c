// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int ret_func(int param1) { return param1; }

void func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int func_res = ret_func(10);

  if (param + func_res > 49) {
    pointer = (int *)malloc(25 * sizeof(int));
    free(pointer);
    freed_flag = 1;
  }

  if (param + func_res > 49) {
    free(pointer); // FLAW
  }
}
