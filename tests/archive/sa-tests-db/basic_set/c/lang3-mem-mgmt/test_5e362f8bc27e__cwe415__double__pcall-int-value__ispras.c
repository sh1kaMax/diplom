// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: pcall-int-value.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока. Вызов функции осуществляется по
// указателю.

#include <stdlib.h>

int callee(int par1) {
  if (par1 > 89)
    return 20;

  return 10;
}

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int local_var = 0;
  int (*func_ptr)(int) = &callee;

  pointer1 = (int *)malloc(23 * sizeof(int));
  pointer2 = (int *)malloc(23 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  if (func_ptr(local_var) > 10) {
    exit(0);
  }

  free(pointer1);
  free(pointer2); // FLAW
  pointer1 = NULL;

  free(pointer1);
}
