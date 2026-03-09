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
// Поточный вариант: if-check-inverted.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, выход в случае ложности проверки

#include <stdlib.h>
#include <string.h>

int buffer[38];
void use_mem_to_keep_memset(int *);

int func(unsigned int param) {
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 28) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (!(index > 38)) {
    exit(0);
  }

  memset(buffer, 0, index * sizeof(int)); // FLAW
  use_mem_to_keep_memset(buffer);

  return result;
}
