// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: pcall-from-struct.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20 в любом
// случае потому проверка в вызывающей функции успешна и выполнение не достигает
// стока. Вызов функции осуществляется по указателю сохраняемому в структуре.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

int callee1(int par1) {
  if (par1 > 73)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 58)
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
  int number = 0;

  int local_var = 3;
  struct Vtab vtab = fill();

  scanf("%d", &number);

  if (vtab.c2(local_var) > 10) {
    exit(0);
  }

  global = (int *)malloc(number * sizeof(int));

  free(global);
}
