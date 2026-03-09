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
// Поточный вариант: call-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по значению
// в вызываемую функцию через её аргумент; возвращаемое из вызываемой функции
// значение равно единице, поэтому проверка в вызывающей функции успешна и
// выполнение завершается, не достигнув стока

#include <stdlib.h>
#include <string.h>

int *pointer = NULL;

struct struct_type {
  int field1;
  int field2;
  int field3;
};

int callee(struct struct_type struct_param) {
  if (struct_param.field2 >= 0)
    return 1;
  else
    return 0;
}

int func(int *param) {
  int freed_flag = 0;

  struct struct_type struct_var = {-5, 0, 5};

  pointer = malloc(sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (callee(struct_var)) {
    exit(0);
  }

  if (pointer) {
    memcpy(pointer, param, sizeof(int));
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
