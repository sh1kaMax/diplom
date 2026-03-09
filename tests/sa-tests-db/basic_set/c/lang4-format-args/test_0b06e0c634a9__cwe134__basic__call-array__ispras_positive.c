// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: call-array.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента локального для
// вызывающей функции массива с константными значениями; возвращаемое из
// вызываемой функции значение нулевое, поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

int callee(int *array_param) {
  if (array_param[1] > 0)
    return 1;
  else
    return 0;
}

void func(void) {
  char format[36] = "Initial format string";

  int local_array[5] = {-1, 0, 1, 2, 3};

  scanf("%35s", format);

  if (callee(local_array)) {
    exit(0);
  }

  printf(format); // FLAW
}
