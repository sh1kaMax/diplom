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
// Поточный вариант: call-array.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента локального для
// вызывающей функции массива с константными значениями; возвращаемое из
// вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока

#include <stdlib.h>
#include <string.h>

int callee(int *array_param) {
  if (array_param[1] > 0)
    return 1;
  else
    return 0;
}

int func(int *param) {
  int *pointer = NULL;
  int freed_flag = 0;

  int local_array[5] = {-1, 0, 1, 2, 3};

  free(pointer);
  freed_flag = 1;

  if (callee(local_array)) {
    exit(0);
  }

  if (pointer) {
    memcpy(pointer, param, sizeof(int)); // FLAW
  }

  if (!freed_flag) {
    free(pointer);
  }
  return freed_flag;
}
