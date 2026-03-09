// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её записью в глобальную
// переменную.
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

void *gf;

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

void func(size_t size) {
  void *f = NULL;

  struct list_type list_tail = {0, 0};
  struct list_type list_head = {1, &list_tail};

  f = malloc(size);

  if (callee(2, &list_head)) {
    exit(0);
  }

  gf = f;
}
