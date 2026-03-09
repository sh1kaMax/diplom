// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: pcall-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается. Вызов функции осуществляется с помощью
// указателя.

#include <stdlib.h>

int callee(int par1) {
  if (par1 > 17)
    return 20;

  return 10;
}

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int local_var = -4;
  int (*func_ptr)(int) = &callee;

  pointer1 = (int *)malloc(18 * sizeof(int));
  pointer2 = (int *)malloc(18 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  if (func_ptr(local_var) == 10) {
    exit(0);
  }

  free(pointer1);
  free(pointer2);
  pointer1 = NULL;

  free(pointer1);
}
