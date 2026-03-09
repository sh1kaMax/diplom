// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-read-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память читается с использованием операции разыменования.
//
// Поточный вариант: call-ret-same-if.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая возвращает свой аргумент, в зависимости от другого
// параметра. Проверка в вызывающей функции неуспешна и выполнение достигает
// стока

#include <stdlib.h>

int *pointer = NULL;

int callee(int par1, int par2) {
  if (par2 <= 10)
    return par1;

  return 10;
}

int func(int param) {
  int result = 0;
  int freed_flag = 0;

  int local_res = callee(param, 20);

  pointer = malloc(sizeof(int));
  *pointer = param;
  free(pointer);
  freed_flag = 1;

  if (local_res != 10) {
    exit(0);
  }

  result = pointer == NULL ? -1 : *pointer; // FLAW

  if (!freed_flag) {
    free(pointer);
  }
  return result;
}
