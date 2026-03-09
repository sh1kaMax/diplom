// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-dynamic-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int result = 0;

void func(void) {
  int *buffer = (int *)malloc(22 * sizeof(int));
  unsigned int index = 0;

  int var;

  index = 22;

  var = 0;

  for (var = 0; var < 19; var++)
    ;

  result = buffer[index]; // FLAW

  free(buffer);
  return;
}
