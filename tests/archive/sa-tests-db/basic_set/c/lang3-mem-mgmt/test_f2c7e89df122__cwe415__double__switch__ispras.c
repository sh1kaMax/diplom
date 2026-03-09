// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int var;

  pointer1 = (int *)malloc(17 * sizeof(int));
  pointer2 = (int *)malloc(17 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  var = 0;

  switch (var) {
  case 0:
    free(pointer1);
    free(pointer2); // FLAW
    pointer1 = NULL;
    break;
  case 1:
    exit(0);
  }

  free(pointer1);
}
