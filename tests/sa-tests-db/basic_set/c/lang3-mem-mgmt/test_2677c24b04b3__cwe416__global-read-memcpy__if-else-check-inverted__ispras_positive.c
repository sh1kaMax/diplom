// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-read-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память читается с использованием стандартной функции memcpy.
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости

#include <stdlib.h>
#include <string.h>

int *pointer = NULL;

int func(int *param) {
  int freed_flag = 0;

  pointer = malloc(sizeof(int));
  *pointer = *param;
  free(pointer);
  freed_flag = 1;

  if (!(freed_flag == 1)) {
    exit(0);
  } else {
    if (pointer) {
      memcpy(param, pointer, sizeof(int)); // FLAW
    }
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
