// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pcall-from-struct.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20 в любом
// случае потому проверка в вызывающей функции успешна и выполнение не достигает
// стока. Вызов функции осуществляется по указателю сохраняемому в структуре.

#include <stdlib.h>

int callee1(int par1) {
  if (par1 > 99)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 87)
    return 200;

  return 100;
}

struct Vtab {
  int (*c1)(int);
  int (*c2)(int);
};

struct Vtab fill() {
  struct Vtab res = {
      callee1,
      callee2,
  };

  return res;
}

void func(void) {
  int divident = 16, divisor = 8, result;
  int var_a = 90;
  int var_b = 90;

  int local_var = 3;
  struct Vtab vtab = fill();

  divisor = var_a - var_b;

  if (vtab.c2(local_var) > 10) {
    exit(0);
  }

  result = divident / divisor;
}
