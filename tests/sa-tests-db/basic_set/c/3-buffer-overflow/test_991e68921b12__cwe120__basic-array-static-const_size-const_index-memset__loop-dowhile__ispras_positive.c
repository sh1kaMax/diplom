// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-static-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>
#include <string.h>

int result = 0;
int buffer[25];
void use_mem_to_keep_memset(int *);

void func(void) {
  unsigned int index = 0;

  int var;

  index = 25 + 1;

  var = 0;

  do {
    var++;
  } while (var < 20);

  memset(buffer, 0, index * sizeof(int)); // FLAW
  use_mem_to_keep_memset(buffer);

  return;
}
