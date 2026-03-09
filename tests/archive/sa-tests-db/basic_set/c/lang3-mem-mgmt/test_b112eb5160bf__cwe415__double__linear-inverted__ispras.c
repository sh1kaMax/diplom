// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <stdlib.h>

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  free(pointer1);
  free(pointer2);
  pointer1 = NULL;

  pointer1 = (int *)malloc(25 * sizeof(int));
  pointer2 = (int *)malloc(25 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  free(pointer1);
}
