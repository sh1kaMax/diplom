// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-read-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память читается с использованием операции разыменования.
//
// Поточный вариант: call-array-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента локального для
// вызывающей функции массива с константными значениями; возвращаемое из
// вызываемой функции значение равно единице, поэтому проверка в вызывающей
// функции успешна и выполнение завершается, не достигнув стока

#include <stdlib.h>

int *pointer = NULL;

int callee(int *array_param) {
  if (array_param[1] >= 0)
    return 1;
  else
    return 0;
}

int func(int param) {
  int result = 0;
  int freed_flag = 0;

  int local_array[5] = {-1, 0, 1, 2, 3};

  pointer = malloc(sizeof(int));
  *pointer = param;
  free(pointer);
  freed_flag = 1;

  if (callee(local_array)) {
    exit(0);
  }

  result = pointer == NULL ? -1 : *pointer;

  if (!freed_flag) {
    free(pointer);
  }
  return result;
}
