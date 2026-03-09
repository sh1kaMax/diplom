// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-dynamic-const_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции

#include <stdlib.h>

int func(unsigned int param, int param2) {
  int *buffer = (int *)malloc(40 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 31) {
    index = (param * 2 + 1);
  }

  if (param2 > 33 && param2 < 34) {
    result = buffer[index];
  }

  free(buffer);
  return result;
}
