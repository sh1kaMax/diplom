// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

void func(void) {
  int iter_var;

  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  for (iter_var = 7; iter_var < 32; iter_var++) {
    pointer1 = (int *)malloc(15 * sizeof(int));
    pointer2 = (int *)malloc(15 * sizeof(int));
    free(pointer2);
    freed_flag = 1;

    free(pointer1);
    free(pointer2); // FLAW
    pointer1 = NULL;
  }

  free(pointer1);
}
