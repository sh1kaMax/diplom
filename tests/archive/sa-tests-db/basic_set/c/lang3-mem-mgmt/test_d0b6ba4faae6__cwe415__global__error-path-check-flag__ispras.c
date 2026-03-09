// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  int flag = 0;

  pointer = (int *)malloc(14 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (freed_flag == 1)
    flag = 1;

  if (flag != 0)
    goto error_label;

  pointer = NULL;

  exit(0);

error_label:
  free(pointer); // FLAW
}
