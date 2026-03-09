// Авторы теста: ИСП РАН
// CWE: 763
// Название: Release of Invalid Pointer or Reference
// Модельный вариант: auto.json
//
// Память выделяется в автоматической памяти (на стеке).
// Адрес выделенной памяти сохраняется в локальной переменной.
// Память освобождается с помощью указателя, не указывающего на кучу.
//
// Поточный вариант: pcall-from-struct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока. Вызов функции осуществляется по
// указателю сохраняемому в структуре.

#include <stdlib.h>

int callee1(int par1) {
  if (par1 > 28)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 72)
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
  int array[21];
  int *pointer = NULL;

  int local_var = -5;
  struct Vtab vtab = fill();

  pointer = array;

  if (vtab.c1(local_var) > 10) {
    exit(0);
  }

  free(pointer); // FLAW
}
