// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-pstruct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по
// указателю в вызываемую функцию через её аргумент; возвращаемое из вызываемой
// функции значение равно единице, поэтому проверка в вызывающей функции успешна
// и выполнение завершается, не достигнув стока.

#include <stdlib.h>

void model_external_func(int external_param);

struct struct_type {
  int field1;
  int field2;
  int field3;
};

int callee(struct struct_type *struct_param) {
  if (struct_param->field2 >= 0)
    return 1;
  else
    return 0;
}

int *func(void) {

  struct struct_type struct_var;
  struct_var.field1 = 9;
  struct_var.field2 = 1;
  struct_var.field3 = 72;

  int *x = malloc(sizeof(int));

  if (callee(&struct_var)) {
    exit(0);
  }

  if (x != NULL) {
    model_external_func(*x);
  }

  return x;
}
