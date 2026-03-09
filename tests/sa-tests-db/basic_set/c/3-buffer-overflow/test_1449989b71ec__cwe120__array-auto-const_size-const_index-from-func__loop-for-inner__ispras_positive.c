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
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 6; }

void func(void) {
  int buffer[35];
  unsigned int index = 0;

  int var, var2;

  index = 35;

  for (var = 0; var < 11; var++) {
    for (var2 = var; var2 < 13; var2++) {
      index = index_change_func(index);
      result = buffer[index]; // FLAW
    }
  }

  return;
}
