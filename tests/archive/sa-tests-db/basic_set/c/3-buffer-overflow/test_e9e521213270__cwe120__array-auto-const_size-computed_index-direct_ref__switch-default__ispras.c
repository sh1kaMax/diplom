// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора выбора

#include <stdlib.h>

int func(unsigned int param) {
  int buffer[27];
  int result = 0;
  unsigned int index = 0;

  int var;

  if (param > 0 && param < 21) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    result = buffer[index];
    break;
  }

  return result;
}
