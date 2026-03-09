// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
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

int store;

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
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  struct list_type list_tail = {0, 0};
  struct list_type list_head = {1, &list_tail};

  scanf("%d", &index);

  if (callee(2, &list_head)) {
    exit(0);
  }

  store = array[index]; // FLAW
}
