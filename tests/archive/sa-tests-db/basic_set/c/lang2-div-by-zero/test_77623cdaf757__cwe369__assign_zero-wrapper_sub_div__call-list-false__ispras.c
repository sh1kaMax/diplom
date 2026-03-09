// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
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

int wrapper(int wrapper_par) { return 1159 / (wrapper_par - 18); }

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
  int divident = 32, divisor = 10, result;

  struct list_type list_tail = {1, 0};
  struct list_type list_head = {0, &list_tail};

  divisor = 18;

  if (callee(2, &list_head)) {
    exit(0);
  }

  result = wrapper(divisor);
}
