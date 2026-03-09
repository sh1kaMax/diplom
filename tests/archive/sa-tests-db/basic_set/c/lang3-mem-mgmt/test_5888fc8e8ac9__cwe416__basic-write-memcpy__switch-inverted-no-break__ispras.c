// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: basic-write-memcpy.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
// Освобожденная память записывается с использованием стандартной функции
// memcpy.
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока

#include <stdlib.h>
#include <string.h>

int func(int *param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int var;

  free(pointer);
  freed_flag = 1;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    if (pointer) {
      memcpy(pointer, param, sizeof(int));
    }
    break;
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
