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
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 380; }

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;

  int var = 0;

  pointer1 = (int *)malloc(27 * sizeof(int));
  pointer2 = pointer1 + 6;

  callee(&var);

  if (var > 691) {
    exit(0);
  }

  free(pointer2); // FLAW
}
