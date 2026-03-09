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
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdlib.h>

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(int param) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  int local_var = 8;

  pointer1 = (int *)malloc(26 * sizeof(int));
  pointer2 = pointer1 + 16;

  if (callee(local_var, 187) > 0) {
    exit(0);
  }

  free(pointer2);
}
