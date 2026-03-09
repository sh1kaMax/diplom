// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdlib.h>

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int local_var = 27;

  pointer1 = (int *)malloc(14 * sizeof(int));
  pointer2 = (int *)malloc(14 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  if (callee(local_var, 47) > 0) {
    exit(0);
  }

  free(pointer1);
  free(pointer2);
  pointer1 = NULL;

  free(pointer1);
}
