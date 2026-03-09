// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-write-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память записывается с использованием стандартной функции
// memcpy.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>
#include <string.h>

int *pointer = NULL;

int func(int *param) {
  int freed_flag = 0;

  int flag = 0;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (freed_flag == 1)
    flag = 1;

  if (flag != 0)
    goto error_label;

  exit(0);

error_label:
  if (pointer) {
    memcpy(pointer, param, sizeof(int)); // FLAW
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
