// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: call-pstruct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по
// указателю в вызываемую функцию через её аргумент; возвращаемое из вызываемой
// функции значение нулевое, поэтому проверка в вызывающей функции неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1068 / (wrapper_par - 12); }

struct struct_type {
  int field1;
  int field2;
  int field3;
};

int callee(struct struct_type *struct_param) {
  if (struct_param->field2 > 20)
    return 1;
  else
    return 0;
}

void func(void) {
  int divident = 35, divisor = 4, result;

  struct struct_type struct_var;
  struct_var.field1 = 10;
  struct_var.field2 = 5;
  struct_var.field3 = 71;

  divisor = 25;

  if (callee(&struct_var)) {
    exit(0);
  }

  result = wrapper(divisor);
}
