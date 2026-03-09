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
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int iter_var;

  int *buffer = (int *)malloc(20 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  for (iter_var = 4; iter_var < 21; iter_var++) {
    scanf("%u", &index);

    result = buffer[index]; // FLAW
  }

  free(buffer);
  return;
}
