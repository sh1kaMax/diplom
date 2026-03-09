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
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости

#include <stdlib.h>

int func(unsigned int param) {
  int *buffer = (int *)malloc(21 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 15) {
    index = (param * 2 + 1);
  }

  if (index >= 21) {
    index = 21 - 1;
  } else {
    result = buffer[index];
  }

  free(buffer);
  return result;
}
