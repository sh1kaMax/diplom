// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-read-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память читается с использованием стандартной функции memcpy.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки, фильтрация и последующий
// переход по метке со стоком.

#include <stdlib.h>
#include <string.h>

int func(int *param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int flag = 0;

  pointer = malloc(sizeof(int));
  *pointer = *param;
  free(pointer);
  freed_flag = 1;

  if (freed_flag == 1)
    flag = 1;

  if (flag != 0) {

    pointer = NULL;

    goto error_label;
  }

  exit(0);

error_label:
  if (pointer) {
    memcpy(param, pointer, sizeof(int));
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
