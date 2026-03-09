// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-static-const_size-computed_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс вычисляется (передаётся в качестве параметра
// функции).
//
// Поточный вариант: call-list.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго элемента списка (реализованного
// с помощью структуры, содержащей значение элемента и указатель на следующий
// элемент), элементы которого инициализируются константными значениями перед
// вызовом; возвращаемое из вызываемой функции значение нулевое, поэтому
// проверка в вызывающей функции неуспешна и выполнение достигает стока

#include <stdlib.h>
#include <string.h>

int buffer[32];
void use_mem_to_keep_memset(int *);

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

int func(unsigned int param) {
  int result = 0;
  unsigned int index = 0;

  struct list_type list_tail = {0, 0};
  struct list_type list_head = {1, &list_tail};

  if (param > 0 && param < 27) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (callee(2, &list_head)) {
    exit(0);
  }

  memset(buffer, 0, index * sizeof(int)); // FLAW
  use_mem_to_keep_memset(buffer);

  return result;
}
