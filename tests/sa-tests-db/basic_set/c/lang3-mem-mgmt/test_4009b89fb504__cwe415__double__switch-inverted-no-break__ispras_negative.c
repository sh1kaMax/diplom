// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока.

#include <stdlib.h>

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int var;

  pointer1 = (int *)malloc(11 * sizeof(int));
  pointer2 = (int *)malloc(11 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    free(pointer1);
    free(pointer2);
    pointer1 = NULL;
    break;
  }

  free(pointer1);
}
