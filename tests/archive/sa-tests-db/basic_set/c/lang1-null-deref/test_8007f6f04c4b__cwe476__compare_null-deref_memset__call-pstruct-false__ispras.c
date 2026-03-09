// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: call-pstruct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по значению
// в вызываемую функцию через её аргумент; возвращаемое из вызываемой функции
// значение равно единице, поэтому проверка в вызывающей функции успешна и
// выполнение завершается, не достигнув стока

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

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
  int template_flag;

  struct struct_type struct_var;
  struct_var.field1 = 1;
  struct_var.field2 = 9;
  struct_var.field3 = 28;

  if (param == NULL) {
    template_flag = 8;
  }

  if (callee(&struct_var)) {
    exit(0);
  }

  memset(param, 0, sizeof(int));
  use_mem_to_keep_memset(param);

  return 0;
}
