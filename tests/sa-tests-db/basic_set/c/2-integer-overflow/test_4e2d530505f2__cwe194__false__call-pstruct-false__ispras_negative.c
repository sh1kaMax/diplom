// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-pstruct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по
// указателю в вызываемую функцию через её аргумент; возвращаемое из вызываемой
// функции значение равно единице, поэтому проверка в вызывающей функции успешна
// и выполнение завершается, не достигнув стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

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

void func(void) {
  char string[23];
  short number = 22;

  struct struct_type struct_var;
  struct_var.field1 = 10;
  struct_var.field2 = 9;
  struct_var.field3 = 46;

  scanf("%hd", &number);
  if (number > 22)
    number = 22;

  if (callee(&struct_var)) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[22] = '\0';
}
