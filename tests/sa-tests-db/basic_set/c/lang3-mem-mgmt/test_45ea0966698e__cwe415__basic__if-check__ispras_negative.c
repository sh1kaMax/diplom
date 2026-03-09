// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
//
// Поточный вариант: if-check.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, выход в случае истинности проверки.

#include <stdlib.h>

void func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  pointer = (int *)malloc(23 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (freed_flag == 1) {
    exit(0);
  }

  free(pointer);
}
