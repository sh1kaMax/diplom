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
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 9; }

void func(void) {
  int buffer[27];
  unsigned int index = 0;

  int var;

  index = 27;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    index = index_change_func(index);
    result = buffer[index];
    break;
  }

  return;
}
