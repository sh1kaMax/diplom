// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
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

char *source_string;

int callee(int *array_param) {
  if (array_param[1] > 0)
    return 1;
  else
    return 0;
}

void func(void) {
  char string[53];
  int number = 52;

  int local_array[5] = {-1, 0, 1, 2, 3};

  scanf("%d", &number);
  if (number > 52)
    number = 52;

  if (callee(local_array)) {
    exit(0);
  }

  strncpy(string, source_string, number); // FLAW
  string[52] = '\0';
}
