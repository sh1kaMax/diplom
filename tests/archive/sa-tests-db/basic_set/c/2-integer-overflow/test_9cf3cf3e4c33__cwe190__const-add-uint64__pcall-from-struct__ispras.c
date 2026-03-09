// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint64.json
//
// Беззнаковое значение задается с помощью константы ULLONG_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: pcall-from-struct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока. Вызов функции осуществляется по
// указателю сохраняемому в структуре.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int callee1(int par1) {
  if (par1 > 29)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 83)
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
  uint64_t data = 0;
  uint64_t result;

  int local_var = 4;
  struct Vtab vtab = fill();

  data = ULLONG_MAX;

  if (vtab.c1(local_var) > 10) {
    exit(0);
  }

  result = data + 1; // FLAW
}
