// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int buffer[34];

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var, var2;

  index = 34;

  for (var = 0; var < 12; var++) {
    for (var2 = var; var2 < 18; var2++) {
      result = buffer[index]; // FLAW
    }
  }

  return;
}
