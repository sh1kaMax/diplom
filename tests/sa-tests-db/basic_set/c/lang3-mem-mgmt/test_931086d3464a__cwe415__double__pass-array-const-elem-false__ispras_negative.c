// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int arr[100];
  arr[38] = !param;
  arr[85] = 7;

  if (param) {
    pointer1 = (int *)malloc(22 * sizeof(int));
    pointer2 = (int *)malloc(22 * sizeof(int));
    free(pointer2);
    freed_flag = 1;
  }

  param = arr[38];

  if (param) {
    free(pointer1);
    free(pointer2);
    pointer1 = NULL;
  }

  free(pointer1);
}
