// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  pointer = (int *)malloc(27 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (freed_flag == 1) {
    pointer = NULL;
  }

  free(pointer);
}
