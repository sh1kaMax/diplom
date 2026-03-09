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
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки

#include <stdlib.h>
#include <string.h>

int *pointer = NULL;

int func(int *param) {
  int freed_flag = 0;

  int var;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  var = (freed_flag == 1 ? 0 : 1);

  if (var) {
    if (pointer) {
      memcpy(pointer, param, sizeof(int));
    }
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
