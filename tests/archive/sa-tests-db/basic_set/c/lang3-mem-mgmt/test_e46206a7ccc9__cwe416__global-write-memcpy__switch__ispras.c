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
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора

#include <stdlib.h>
#include <string.h>

int *pointer = NULL;

int func(int *param) {
  int freed_flag = 0;

  int var;

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  var = 0;

  switch (var) {
  case 0:
    if (pointer) {
      memcpy(pointer, param, sizeof(int)); // FLAW
    }
    break;
  case 1:
    exit(0);
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
