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
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 5; }

void func(void) {
  int buffer[34];
  unsigned int index = 0;

  int var;

  index = 34;

  var = 0;

  do {
    var++;
  } while (var < 15);

  index = index_change_func(index);
  result = buffer[index]; // FLAW

  return;
}
