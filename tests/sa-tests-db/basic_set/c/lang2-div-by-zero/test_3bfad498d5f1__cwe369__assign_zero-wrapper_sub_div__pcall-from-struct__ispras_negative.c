// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: pcall-from-struct.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20 в любом
// случае потому проверка в вызывающей функции успешна и выполнение не достигает
// стока. Вызов функции осуществляется по указателю сохраняемому в структуре.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1493 / (wrapper_par - 17); }

int callee1(int par1) {
  if (par1 > 45)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 81)
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
  int divident = 24, divisor = 4, result;

  int local_var = -1;
  struct Vtab vtab = fill();

  divisor = 17;

  if (vtab.c2(local_var) > 10) {
    exit(0);
  }

  result = wrapper(divisor);
}
