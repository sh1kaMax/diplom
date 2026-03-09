// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdlib.h>

int external_func(void);

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  pointer1 = (int *)malloc(10 * sizeof(int));
  pointer2 = (int *)malloc(10 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  if (external_func()) {

    pointer2 = NULL;

    goto error_label;
  }

  exit(0);

error_label:
  free(pointer1);
  free(pointer2);
  pointer1 = NULL;

  free(pointer1);
}
