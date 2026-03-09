// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
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

const char safe_format[] = "Safe format string";

int callee1(int par1) {
  if (par1 > 35)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 99)
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
  char format[63] = "Initial format string";

  int local_var = 2;
  struct Vtab vtab = fill();

  scanf("%62s", format);

  if (vtab.c2(local_var) > 10) {
    exit(0);
  }

  printf(format);
}
