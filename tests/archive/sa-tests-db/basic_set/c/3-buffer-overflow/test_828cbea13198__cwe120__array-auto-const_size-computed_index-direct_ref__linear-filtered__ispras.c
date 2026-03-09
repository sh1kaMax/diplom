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
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними

#include <stdlib.h>

int func(unsigned int param) {
  int buffer[20];
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 13) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  index = 20 - 1;

  result = buffer[index];

  return result;
}
