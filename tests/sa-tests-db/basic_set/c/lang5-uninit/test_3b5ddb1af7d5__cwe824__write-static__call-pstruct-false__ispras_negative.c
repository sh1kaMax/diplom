// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: write-static.json
//
// Запись значения по неинициализированному статическому указателю.
// Запись не производится, так как значение неинициализированного глобального
// указателя равно нулю.
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

void func(int *input_ptr) {

  struct struct_type struct_var;
  struct_var.field1 = 6;
  struct_var.field2 = 3;
  struct_var.field3 = 25;

  static int *x;

  if (callee(&struct_var)) {
    exit(0);
  }

  if (x != NULL) {
    *x = 78;
  }
}
