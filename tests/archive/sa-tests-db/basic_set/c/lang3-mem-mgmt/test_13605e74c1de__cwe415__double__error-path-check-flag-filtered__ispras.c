// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int flag = 0;

  pointer1 = (int *)malloc(26 * sizeof(int));
  pointer2 = (int *)malloc(26 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  if (freed_flag == 1)
    flag = 1;

  if (flag != 0) {

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
