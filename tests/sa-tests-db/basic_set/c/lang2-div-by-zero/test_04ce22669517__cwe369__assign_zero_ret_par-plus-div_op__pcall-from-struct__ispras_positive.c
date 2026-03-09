// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: pcall-from-struct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока. Вызов функции осуществляется по
// указателю сохраняемому в структуре.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

int callee1(int par1) {
  if (par1 > 79)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 69)
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
  int divident = 58, divisor = 7, result;

  int local_var = 2;
  struct Vtab vtab = fill();

  divisor = wrapper(67);
  divisor -= 67;

  if (vtab.c1(local_var) > 10) {
    exit(0);
  }

  result = divident / divisor; // FLAW
}
