// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: diamond-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// простых условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  if (param > 49) {
    pointer1 = (int *)malloc(26 * sizeof(int));
    pointer2 = (int *)malloc(26 * sizeof(int));
    free(pointer2);
    freed_flag = 1;
  }

  if (param <= 49) {
    free(pointer1);
    free(pointer2);
    pointer1 = NULL;
  }

  free(pointer1);
}
