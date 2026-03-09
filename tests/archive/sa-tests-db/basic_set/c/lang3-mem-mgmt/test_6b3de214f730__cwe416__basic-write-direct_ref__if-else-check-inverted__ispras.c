// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-write-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память записывается с использованием операции разыменования.
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости

#include <stdlib.h>

int func(int param) {
  int *pointer = NULL;
  int freed_flag = 0;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (!(freed_flag == 1)) {
    exit(0);
  } else {
    if (pointer) {
      *pointer = param; // FLAW
    }
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
