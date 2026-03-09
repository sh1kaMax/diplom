// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-local-array-const_size-func-safe-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. В функции доступа есть проверка на границы индекса. Индекс
// является константой.
//
// Поточный вариант: pcall-from-struct.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20 в любом
// случае потому проверка в вызывающей функции успешна и выполнение не достигает
// стока. Вызов функции осуществляется по указателю сохраняемому в структуре.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[22];
  int cur_index = 0;
  for (; cur_index < 22; cur_index++)
    buffer[cur_index] = 15;
  if (elem_index >= 22)
    return -1;
  return buffer[elem_index];
}

int callee1(int par1) {
  if (par1 > 58)
    return 20;

  return 10;
}

int callee2(int par2) {
  if (par2 > 70)
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

  int local_var = 2;
  struct Vtab vtab = fill();

  index = 22;

  if (vtab.c2(local_var) > 10) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}
