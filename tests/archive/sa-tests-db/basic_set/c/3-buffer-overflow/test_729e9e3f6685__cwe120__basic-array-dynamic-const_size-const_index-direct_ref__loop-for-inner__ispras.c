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
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int result = 0;

void func(void) {
  int *buffer = (int *)malloc(34 * sizeof(int));
  unsigned int index = 0;

  int var, var2;

  index = 34;

  for (var = 0; var < 11; var++) {
    for (var2 = var; var2 < 10; var2++) {
      result = buffer[index]; // FLAW
    }
  }

  free(buffer);
  return;
}
