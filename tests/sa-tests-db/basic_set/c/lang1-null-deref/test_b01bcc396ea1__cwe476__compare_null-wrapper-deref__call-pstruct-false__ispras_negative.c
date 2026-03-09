// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: call-pstruct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по значению
// в вызываемую функцию через её аргумент; возвращаемое из вызываемой функции
// значение равно единице, поэтому проверка в вызывающей функции успешна и
// выполнение завершается, не достигнув стока

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

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

int func(int *param) {
  int template_flag = 0;

  struct struct_type struct_var;
  struct_var.field1 = 0;
  struct_var.field2 = 0;
  struct_var.field3 = 94;

  if (param == NULL) {
    template_flag = 73;
  }

  if (callee(&struct_var)) {
    exit(0);
  }

  wrapper(param);

  return 0;
}
