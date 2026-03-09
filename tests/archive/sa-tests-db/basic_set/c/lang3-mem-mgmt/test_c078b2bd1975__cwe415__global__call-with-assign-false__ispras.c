// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

int *pointer = NULL;

void callee(int *pointer_param) { *pointer_param = 205; }

void func(void) {
  int freed_flag = 0;

  int var = 0;

  pointer = (int *)malloc(12 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  callee(&var);

  if (var > 19) {
    exit(0);
  }

  free(pointer);
}
