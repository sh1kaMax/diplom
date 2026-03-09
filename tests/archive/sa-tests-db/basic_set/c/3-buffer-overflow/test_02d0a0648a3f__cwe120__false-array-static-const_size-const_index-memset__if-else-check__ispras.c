// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-static-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: if-else-check.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// устовием которого является условие наличия уязвимости.

#include <stdlib.h>
#include <string.h>

int result = 0;
int buffer[40];
void use_mem_to_keep_memset(int *);

void func(void) {
  unsigned int index = 0;

  index = 40 + 1;

  if (index > 40) {
    exit(0);
  } else {
    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
  }

  return;
}
