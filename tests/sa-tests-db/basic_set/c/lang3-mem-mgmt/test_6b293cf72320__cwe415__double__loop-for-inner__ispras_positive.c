// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int var, var2;

  pointer1 = (int *)malloc(17 * sizeof(int));
  pointer2 = (int *)malloc(17 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  for (var = 0; var < 11; var++) {
    for (var2 = var; var2 < 18; var2++) {
      free(pointer1);
      free(pointer2); // FLAW
      pointer1 = NULL;
    }
  }

  free(pointer1);
}
