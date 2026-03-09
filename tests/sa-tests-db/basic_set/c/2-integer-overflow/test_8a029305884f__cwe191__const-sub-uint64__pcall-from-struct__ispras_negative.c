// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-uint64.json
//
// Беззнаковое значение задается с помощью константы 0.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
//
// Поточный вариант: pcall-from-struct.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20 в любом
// случае потому проверка в вызывающей функции успешна и выполнение не достигает
// стока. Вызов функции осуществляется по указателю сохраняемому в структуре.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int callee1(int par1) {
  if (par1 > 38)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 55)
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
  uint64_t data = 1;
  uint64_t result;

  int local_var = 5;
  struct Vtab vtab = fill();

  data = 0;

  if (vtab.c2(local_var) > 10) {
    exit(0);
  }

  result = data - 1;
}
