// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: pcall-from-struct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока. Вызов функции осуществляется по
// указателю сохраняемому в структуре.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int callee1(int par1) {
  if (par1 > 30)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 63)
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
  char string[28];
  int number = 27;

  int local_var = 5;
  struct Vtab vtab = fill();

  scanf("%d", &number);
  if (number > 27)
    number = 27;

  if (vtab.c1(local_var) > 10) {
    exit(0);
  }

  strncpy(string, source_string, number); // FLAW
  string[27] = '\0';
}
