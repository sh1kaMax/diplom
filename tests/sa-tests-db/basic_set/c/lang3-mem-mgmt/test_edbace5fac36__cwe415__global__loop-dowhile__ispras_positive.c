// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int *pointer = NULL;

void func(void) {
  int freed_flag = 0;

  int var;

  pointer = (int *)malloc(11 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  var = 0;

  do {
    var++;
  } while (var < 17);

  free(pointer); // FLAW
}
