// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-write-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память записывается с использованием операции разыменования.
//
// Поточный вариант: if-check.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, выход в случае истинности проверки

#include <stdlib.h>

int *pointer = NULL;

int func(int param) {
  int freed_flag = 0;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (freed_flag == 1) {
    exit(0);
  }

  if (pointer) {
    *pointer = param;
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
