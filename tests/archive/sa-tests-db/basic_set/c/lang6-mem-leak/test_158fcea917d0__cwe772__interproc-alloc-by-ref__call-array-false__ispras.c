// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-alloc-by-ref.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор выделяется в пользовательской функции по указателю.
//
// Поточный вариант: call-array-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента локального для
// вызывающей функции массива с константными значениями; возвращаемое из
// вызываемой функции значение равно единице, поэтому проверка в вызывающей
// функции успешна и выполнение завершается, не достигнув стока.

#include <stdio.h>
#include <stdlib.h>

void my_fopen(FILE **ptr, const char *my_path) {
  if (ptr != NULL) {
    *ptr = fopen(my_path, "r");
  }
}

int callee(int *array_param) {
  if (array_param[1] >= 0)
    return 1;
  else
    return 0;
}

void func(const char *path) {
  FILE *f = NULL;

  int local_array[5] = {-1, 0, 1, 2, 3};

  my_fopen(&f, path);

  if (callee(local_array)) {
    exit(0);
  }

  if (f != NULL) {
    fclose(f);
  }
}
