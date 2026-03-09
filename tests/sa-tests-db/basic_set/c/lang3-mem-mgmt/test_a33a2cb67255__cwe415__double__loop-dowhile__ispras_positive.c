// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int var;

  pointer1 = (int *)malloc(30 * sizeof(int));
  pointer2 = (int *)malloc(30 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  var = 0;

  do {
    var++;
  } while (var < 14);

  free(pointer1);
  free(pointer2); // FLAW
  pointer1 = NULL;

  free(pointer1);
}
