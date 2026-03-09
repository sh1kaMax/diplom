// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: global.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
//
// Поточный вариант: pcall-from-struct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока. Вызов функции осуществляется по
// указателю сохраняемому в структуре.

#include <stdlib.h>

int *pointer = NULL;

int callee1(int par1) {
  if (par1 > 94)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 14)
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
  int freed_flag = 0;

  int local_var = 3;
  struct Vtab vtab = fill();

  pointer = (int *)malloc(16 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  if (vtab.c1(local_var) > 10) {
    exit(0);
  }

  free(pointer); // FLAW
}
