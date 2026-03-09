// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: pcall-from-struct.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20 в любом
// случае потому проверка в вызывающей функции успешна и выполнение не достигает
// стока. Вызов функции осуществляется по указателю сохраняемому в структуре.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1617 / wrapper_par; }

int callee1(int par1) {
  if (par1 > 64)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 34)
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
  int divident = 15, divisor = 4, result;

  int local_var = -3;
  struct Vtab vtab = fill();

  divisor = 0;

  if (vtab.c2(local_var) > 10) {
    exit(0);
  }

  result = wrapper(divisor);
}
