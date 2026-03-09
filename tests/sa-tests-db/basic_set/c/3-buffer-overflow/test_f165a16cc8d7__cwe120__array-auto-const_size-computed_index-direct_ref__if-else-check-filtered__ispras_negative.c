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
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости

#include <stdlib.h>

int func(unsigned int param) {
  int buffer[22];
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 14) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (index >= 22) {
    index = 22 - 1;
  } else {
    result = buffer[index];
  }

  return result;
}
