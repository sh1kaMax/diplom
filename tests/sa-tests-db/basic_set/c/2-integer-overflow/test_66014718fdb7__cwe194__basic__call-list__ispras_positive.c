// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-list.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента списка (реализованного
// с помощью структуры, содержащей значение элемента и указатель на следующий
// элемент), элементы которого инициализируются константными значениями перед
// вызовом; возвращаемое из вызываемой функции значение нулевое, поэтому
// проверка в вызывающей функции неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

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
  char string[33];
  short number = 32;

  struct list_type list_tail = {0, 0};
  struct list_type list_head = {1, &list_tail};

  scanf("%hd", &number);
  if (number > 32)
    number = 32;

  if (callee(2, &list_head)) {
    exit(0);
  }

  strncpy(string, source_string, number); // FLAW
  string[32] = '\0';
}
