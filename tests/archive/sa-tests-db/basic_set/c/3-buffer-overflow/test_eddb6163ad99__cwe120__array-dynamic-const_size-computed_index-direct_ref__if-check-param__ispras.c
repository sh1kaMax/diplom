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
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции

#include <stdlib.h>

int func(unsigned int param, int param2) {
  int *buffer = (int *)malloc(22 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 13) {
    index = (param * 2 + 1);
  }

  if (param2 > 41) {
    result = buffer[index]; // FLAW
  }

  free(buffer);
  return result;
}
