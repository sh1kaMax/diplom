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
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdio.h>

void func(void) {
  int buffer[33];
  int result = 0;
  unsigned int index = 0;

  int var;

  scanf("%u", &index);

  var = 0;

  do {
    var++;
  } while (var < 13);

  result = buffer[index]; // FLAW

  return;
}
