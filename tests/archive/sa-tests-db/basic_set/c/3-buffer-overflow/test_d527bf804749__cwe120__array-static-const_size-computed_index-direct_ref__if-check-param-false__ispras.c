// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-static-const_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции

#include <stdlib.h>

int buffer[27];

int func(unsigned int param, int param2) {
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 20) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (param2 > 27 && param2 < 28) {
    result = buffer[index];
  }

  return result;
}
