// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-static-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffer[36];
void use_mem_to_keep_memset(int *);

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var, var2;

  scanf("%u", &index);

  for (var = 0; var < 12; var++) {
    for (var2 = var; var2 < 11; var2++) {
      memset(buffer, 0, index * sizeof(int)); // FLAW
      use_mem_to_keep_memset(buffer);
    }
  }

  return;
}
