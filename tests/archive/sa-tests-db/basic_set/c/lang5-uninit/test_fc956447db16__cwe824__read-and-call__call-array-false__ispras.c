// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-call.json
//
// Передача значения неинициализированного указателя во внешнюю функцию.
//
// Поточный вариант: call-array-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента локального для
// вызывающей функции массива с константными значениями; возвращаемое из
// вызываемой функции значение равно единице, поэтому проверка в вызывающей
// функции успешна и выполнение завершается, не достигнув стока.

#include <stdlib.h>

int model_external_func(int *external_param);

int callee(int *array_param) {
  if (array_param[1] >= 0)
    return 1;
  else
    return 0;
}

int func(void) {
  int result = 0;

  int local_array[5] = {-1, 0, 1, 2, 3};

  int *x;

  if (callee(local_array)) {
    exit(0);
  }

  result = model_external_func(x);

  return result;
}
