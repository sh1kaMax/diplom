// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: pcall-from-struct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока. Вызов функции осуществляется по
// указателю сохраняемому в структуре.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 10; }

int callee1(int par1) {
  if (par1 > 17)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 77)
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
  int buffer[38];
  unsigned int index = 0;

  int local_var = -3;
  struct Vtab vtab = fill();

  index = 38;

  if (vtab.c1(local_var) > 10) {
    exit(0);
  }

  index = index_change_func(index);
  result = buffer[index]; // FLAW

  return;
}
