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
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 2; }

void func(void) {
  int iter_var;

  int buffer[30];
  unsigned int index = 0;

  for (iter_var = 3; iter_var < 11; iter_var++) {
    index = 30;

    index = index_change_func(index);
    result = buffer[index]; // FLAW
  }

  return;
}
