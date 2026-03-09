// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_memset.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: call-array.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента локального для
// вызывающей функции массива с константными значениями; возвращаемое из
// вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int callee(int *array_param) {
  if (array_param[1] > 0)
    return 1;
  else
    return 0;
}

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_array[5] = {-1, 0, 1, 2, 3};

  pointer = NULL;

  if (callee(local_array)) {
    exit(0);
  }

  memset(pointer, 0, sizeof(int)); // FLAW
  use_mem_to_keep_memset(pointer);
}
