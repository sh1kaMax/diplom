// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-array-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента локального для
// вызывающей функции массива с константными значениями; возвращаемое из
// вызываемой функции значение равно единице, поэтому проверка в вызывающей
// функции успешна и выполнение завершается, не достигнув стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 90; }

int callee(int *array_param) {
  if (array_param[1] >= 0)
    return 1;
  else
    return 0;
}

void func(void) {
  int divident = 51, divisor = 6, result;

  int local_array[5] = {-1, 0, 1, 2, 3};

  divisor = wrapper(66);
  divisor -= 90;

  if (callee(local_array)) {
    exit(0);
  }

  result = divident / divisor;
}
