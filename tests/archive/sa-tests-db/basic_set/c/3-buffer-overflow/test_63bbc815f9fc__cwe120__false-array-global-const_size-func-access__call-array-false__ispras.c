// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
//
// Поточный вариант: call-array-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента локального для
// вызывающей функции массива с константными значениями; возвращаемое из
// вызываемой функции значение равно единице, поэтому проверка в вызывающей
// функции успешна и выполнение завершается, не достигнув стока.

#include <stdlib.h>

int buffer[40];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

int callee(int *array_param) {
  if (array_param[1] >= 0)
    return 1;
  else
    return 0;
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int local_array[5] = {-1, 0, 1, 2, 3};

  index = 40;

  if (callee(local_array)) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}
