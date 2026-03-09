// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: local-array-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. Индекс является константой.
//
// Поточный вариант: pcall-from-struct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока. Вызов функции осуществляется по
// указателю сохраняемому в структуре.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[35];
  int cur_index = 0;
  for (; cur_index < 35; cur_index++)
    buffer[cur_index] = 100;
  return buffer[elem_index];
}

int callee1(int par1) {
  if (par1 > 65)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 96)
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
  int result = 0;
  unsigned int index = 0;

  int local_var = -4;
  struct Vtab vtab = fill();

  index = 35;

  if (vtab.c1(local_var) > 10) {
    exit(0);
  }

  result = get_buffer_elem(index); // FLAW

  return;
}
