// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-computed_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера вычисляется (передаётся в качестве параметра функции).
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними

#include <stdlib.h>

int func(unsigned int param) {
  int buffer[param];
  int result = 0;
  unsigned int index = 0;

  int var;

  index = param * 2;

  var = 0;

  while (var < 10)
    var++;

  result = buffer[index]; // FLAW

  return result;
}
