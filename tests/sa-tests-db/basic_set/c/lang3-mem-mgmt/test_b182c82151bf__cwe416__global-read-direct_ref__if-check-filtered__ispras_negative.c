// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-read-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память читается с использованием операции разыменования.
//
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки

#include <stdlib.h>

int *pointer = NULL;

int func(int param) {
  int result = 0;
  int freed_flag = 0;

  pointer = malloc(sizeof(int));
  *pointer = param;
  free(pointer);
  freed_flag = 1;

  if (freed_flag == 1) {
    pointer = NULL;
  }

  result = pointer == NULL ? -1 : *pointer;

  if (!freed_flag) {
    free(pointer);
  }
  return result;
}
