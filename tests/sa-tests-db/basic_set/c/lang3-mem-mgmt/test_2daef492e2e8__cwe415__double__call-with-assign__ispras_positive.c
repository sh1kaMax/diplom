// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 469; }

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int var = 0;

  pointer1 = (int *)malloc(25 * sizeof(int));
  pointer2 = (int *)malloc(25 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  callee(&var);

  if (var > 491) {
    exit(0);
  }

  free(pointer1);
  free(pointer2); // FLAW
  pointer1 = NULL;

  free(pointer1);
}
