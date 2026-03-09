// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: if-else-check.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// устовием которого является условие наличия уязвимости.

#include <stdlib.h>

int result = 0;

void func(void) {
  int *buffer = (int *)malloc(38 * sizeof(int));
  unsigned int index = 0;

  index = 38;

  if (index >= 38) {
    exit(0);
  } else {
    result = buffer[index];
  }

  free(buffer);
  return;
}
