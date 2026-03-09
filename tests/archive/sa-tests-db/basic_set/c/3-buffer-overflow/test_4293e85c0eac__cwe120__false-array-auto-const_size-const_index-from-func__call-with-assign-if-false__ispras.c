// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 8; }

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 277;
}

void func(void) {
  int buffer[23];
  unsigned int index = 0;

  int var = 0;

  index = 23;

  callee(&var, 8);

  if (var > 164) {
    exit(0);
  }

  index = index_change_func(index);
  result = buffer[index];

  return;
}
