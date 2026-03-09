// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdlib.h>

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  pointer1 = (int *)malloc(24 * sizeof(int));
  pointer2 = (int *)malloc(24 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  pointer2 = NULL;

  free(pointer1);
  free(pointer2);
  pointer1 = NULL;

  free(pointer1);
}
