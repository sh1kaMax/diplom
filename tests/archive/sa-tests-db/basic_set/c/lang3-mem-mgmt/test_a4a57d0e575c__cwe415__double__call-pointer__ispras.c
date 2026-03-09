// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: call-pointer.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой непосредственно передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение нулевое,
// поэтому проверка в вызывающей функции неуспешна и выполнение достигает стока.

#include <stdlib.h>

int callee(int *pointer_param) {
  if (*pointer_param > 0)
    return 1;
  else
    return 0;
}

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  int var = 0;

  pointer1 = (int *)malloc(25 * sizeof(int));
  pointer2 = (int *)malloc(25 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  if (callee(&var)) {
    exit(0);
  }

  free(pointer1);
  free(pointer2); // FLAW
  pointer1 = NULL;

  free(pointer1);
}
