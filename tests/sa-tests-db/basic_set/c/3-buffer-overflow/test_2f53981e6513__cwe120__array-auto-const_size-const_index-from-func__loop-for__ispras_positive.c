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
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 8; }

void func(void) {
  int buffer[29];
  unsigned int index = 0;

  int var;

  index = 29;

  var = 0;

  for (var = 0; var < 11; var++)
    ;

  index = index_change_func(index);
  result = buffer[index]; // FLAW

  return;
}
