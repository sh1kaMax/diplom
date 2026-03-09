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
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними

#include <stdlib.h>

int func(unsigned int param) {
  int *buffer = (int *)malloc(35 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  int var;

  if (param > 0 && param < 28) {
    index = (param * 2 + 1);
  }

  var = 0;

  do {
    var++;
  } while (var < 10);

  result = buffer[index]; // FLAW

  free(buffer);
  return result;
}
