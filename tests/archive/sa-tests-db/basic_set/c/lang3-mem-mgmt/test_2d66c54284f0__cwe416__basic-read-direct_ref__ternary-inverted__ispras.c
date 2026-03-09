// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-read-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память читается с использованием операции разыменования.
//
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки

#include <stdlib.h>

int func(int param) {
  int result = 0;
  int *pointer = NULL;
  int freed_flag = 0;

  int var;

  pointer = malloc(sizeof(int));
  *pointer = param;
  free(pointer);
  freed_flag = 1;

  var = (freed_flag == 1 ? 0 : 1);

  if (var) {
    result = pointer == NULL ? -1 : *pointer;
  }

  if (!freed_flag) {
    free(pointer);
  }
  return result;
}
