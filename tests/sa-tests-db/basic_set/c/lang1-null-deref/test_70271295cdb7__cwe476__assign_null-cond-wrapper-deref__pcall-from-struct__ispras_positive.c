// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-cond-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр больше нуля.
//
// Поточный вариант: pcall-from-struct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока. Вызов функции осуществляется по
// указателю сохраняемому в структуре.

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

int callee1(int par1) {
  if (par1 > 77)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 37)
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
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var = -2;
  struct Vtab vtab = fill();

  pointer = NULL;

  if (vtab.c1(local_var) > 10) {
    exit(0);
  }

  wrapper(pointer, 31); // FLAW
}
