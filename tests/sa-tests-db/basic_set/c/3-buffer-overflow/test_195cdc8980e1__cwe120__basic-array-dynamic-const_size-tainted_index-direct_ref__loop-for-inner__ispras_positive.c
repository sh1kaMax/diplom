// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// basic-array-dynamic-const_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int *buffer = (int *)malloc(29 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  int var, var2;

  scanf("%u", &index);

  for (var = 0; var < 18; var++) {
    for (var2 = var; var2 < 11; var2++) {
      result = buffer[index]; // FLAW
    }
  }

  free(buffer);
  return;
}
