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
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником

#include <stdlib.h>

int func(unsigned int param) {
  int *buffer = (int *)malloc(37 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  index = 37 - 1;

  if (param > 0 && param < 30) {
    index = (param * 2 + 1);
  }

  result = buffer[index]; // FLAW

  free(buffer);
  return result;
}
