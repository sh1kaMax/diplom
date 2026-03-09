// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-auto-const_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdio.h>

void func(void) {
  int buffer[23];
  int result = 0;
  unsigned int index = 0;

  int var, var2;

  scanf("%u", &index);

  for (var = 0; var < 16; var++) {
    for (var2 = var; var2 < 20; var2++) {
      result = buffer[index]; // FLAW
    }
  }

  return;
}
