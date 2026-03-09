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
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции

#include <stdlib.h>

int buffer[40];

int func(unsigned int param, int param2) {
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 32) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (param2 > 4 && param2 < 59) {
    result = buffer[index]; // FLAW
  }

  return result;
}
