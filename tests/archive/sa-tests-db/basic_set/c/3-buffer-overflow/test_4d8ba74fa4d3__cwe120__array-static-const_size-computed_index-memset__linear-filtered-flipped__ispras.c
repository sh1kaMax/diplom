// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-static-const_size-computed_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс вычисляется (передаётся в качестве параметра
// функции).
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником

#include <stdlib.h>
#include <string.h>

int buffer[21];
void use_mem_to_keep_memset(int *);

int func(unsigned int param) {
  int result = 0;
  unsigned int index = 0;

  index = 21;

  if (param > 0 && param < 16) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  memset(buffer, 0, index * sizeof(int)); // FLAW
  use_mem_to_keep_memset(buffer);

  return result;
}
