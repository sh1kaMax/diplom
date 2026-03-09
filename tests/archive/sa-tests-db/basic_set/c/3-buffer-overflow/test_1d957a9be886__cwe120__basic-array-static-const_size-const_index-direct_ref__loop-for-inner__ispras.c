// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-static-const_size-const_index-direct_ref.json
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

int result = 0;
int buffer[24];

void func(void) {
  unsigned int index = 0;

  int var, var2;

  index = 24;

  for (var = 0; var < 17; var++) {
    for (var2 = var; var2 < 17; var2++) {
      result = buffer[index]; // FLAW
    }
  }

  return;
}
