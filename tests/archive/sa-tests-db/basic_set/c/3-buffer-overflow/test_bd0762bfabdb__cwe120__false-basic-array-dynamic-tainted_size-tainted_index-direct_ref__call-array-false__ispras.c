// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-tainted_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: call-array-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента локального для
// вызывающей функции массива с константными значениями; возвращаемое из
// вызываемой функции значение равно единице, поэтому проверка в вызывающей
// функции успешна и выполнение завершается, не достигнув стока.

#include <stdio.h>
#include <stdlib.h>

int result = 0;

int callee(int *array_param) {
  if (array_param[1] >= 0)
    return 1;
  else
    return 0;
}

void func(void) {
  unsigned int size;
  scanf("%u", &size);
  int *buffer = (int *)malloc(size * sizeof(int));
  unsigned int index = 0;

  int local_array[5] = {-1, 0, 1, 2, 3};

  scanf("%u", &index);

  if (callee(local_array)) {
    exit(0);
  }

  result = buffer[index];

  free(buffer);
  return;
}
