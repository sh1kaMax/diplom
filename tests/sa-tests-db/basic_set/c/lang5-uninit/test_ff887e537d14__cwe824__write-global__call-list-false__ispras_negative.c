// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: write-global.json
//
// Запись значения по неинициализированному глобальному указателю.
// Запись не производится, так как значение неинициализированного глобального
// указателя равно нулю.
//
// Поточный вариант: call-list-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента списка (реализованного
// с помощью структуры, содержащей значение элемента и указатель на следующий
// элемент), элементы которого инициализируются константными значениями перед
// вызовом; возвращаемое из вызываемой функции значение равно единице, поэтому
// проверка в вызывающей функции успешна и выполнение завершается, не достигнув
// стока.

#include <stdlib.h>

int *x;

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

void func(int *input_ptr) {

  struct list_type list_tail = {1, 0};
  struct list_type list_head = {0, &list_tail};

  if (callee(2, &list_head)) {
    exit(0);
  }

  if (x != NULL) {
    *x = -63;
  }
}
