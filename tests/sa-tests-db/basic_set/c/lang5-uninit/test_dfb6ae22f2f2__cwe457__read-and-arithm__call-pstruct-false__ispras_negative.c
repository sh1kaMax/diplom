// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-arithm.json
//
// Чтение значения неинициализированной переменной для использования при
// вычислении выражения.
//
// Поточный вариант: call-pstruct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по
// указателю в вызываемую функцию через её аргумент; возвращаемое из вызываемой
// функции значение равно единице, поэтому проверка в вызывающей функции успешна
// и выполнение завершается, не достигнув стока.

#include <stdlib.h>

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

int func(void) {
  int result = 0;

  struct struct_type struct_var;
  struct_var.field1 = 4;
  struct_var.field2 = 5;
  struct_var.field3 = 10;

  int x;

  if (callee(&struct_var)) {
    exit(0);
  }

  result = x + 1;

  return result;
}
