// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-read-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память читается с использованием операции разыменования.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними

#include <stdlib.h>

int *pointer = NULL;

int func(int param) {
  int result = 0;
  int freed_flag = 0;

  int var;

  pointer = malloc(sizeof(int));
  *pointer = param;
  free(pointer);
  freed_flag = 1;

  var = 0;

  for (var = 0; var < 10; var++)
    ;

  result = pointer == NULL ? -1 : *pointer; // FLAW

  if (!freed_flag) {
    free(pointer);
  }
  return result;
}
