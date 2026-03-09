// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: call-list.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента списка (реализованного
// с помощью структуры, содержащей значение элемента и указатель на следующий
// элемент), элементы которого инициализируются константными значениями перед
// вызовом; возвращаемое из вызываемой функции значение нулевое, поэтому
// проверка в вызывающей функции неуспешна и выполнение достигает стока.

#include <stdlib.h>

struct list_type {
  int field;
  struct list_type *next;
};

int callee(int element, struct list_type *list_param) {
  while (list_param) {
    element--;
    if (element == 0) {
      return list_param->field;
    }
    list_param = list_param->next;
  }
  return 0;
}

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  struct list_type list_tail = {0, 0};
  struct list_type list_head = {1, &list_tail};

  pointer1 = (int *)malloc(10 * sizeof(int));
  pointer2 = (int *)malloc(10 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  if (callee(2, &list_head)) {
    exit(0);
  }

  free(pointer1);
  free(pointer2); // FLAW
  pointer1 = NULL;

  free(pointer1);
}
