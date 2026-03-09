// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-return.json
//
// Возврат значения неинициализированного указателя из функции.
//
// Поточный вариант: call-struct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по значению
// в вызываемую функцию через её аргумент; возвращаемое из вызываемой функции
// значение нулевое, поэтому проверка в вызывающей функции неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

struct struct_type {
  int field1;
  int field2;
  int field3;
};

int callee(struct struct_type struct_param) {
  if (struct_param.field2 > 0)
    return 1;
  else
    return 0;
}

int *func(void) {
  int *result = NULL;

  struct struct_type struct_var = {-5, 0, 5};

  int *x;

  if (callee(struct_var)) {
    exit(0);
  }

  result = x; // FLAW

  return result;
}
