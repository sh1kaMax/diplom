// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
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

int buffer[30];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

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
  int result = 0;
  unsigned int index = 0;

  struct list_type list_tail = {1, 0};
  struct list_type list_head = {0, &list_tail};

  index = 30;

  if (callee(2, &list_head)) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}
