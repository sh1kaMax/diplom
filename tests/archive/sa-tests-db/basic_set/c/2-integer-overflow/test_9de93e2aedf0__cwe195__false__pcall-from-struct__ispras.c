// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: pcall-from-struct.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20 в любом
// случае потому проверка в вызывающей функции успешна и выполнение не достигает
// стока. Вызов функции осуществляется по указателю сохраняемому в структуре.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int callee1(int par1) {
  if (par1 > 75)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 94)
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

  int local_var = 4;
  struct Vtab vtab = fill();

  scanf("%d", &number);
  if (number > 27)
    number = 27;

  if (vtab.c2(local_var) > 10) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[27] = '\0';
}
