// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-dynamic-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdlib.h>
#include <string.h>

int result = 0;
void use_mem_to_keep_memset(int *);

void func(void) {
  int *buffer = (int *)malloc(33 * sizeof(int));
  unsigned int index = 0;

  int var;

  index = 33 + 1;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
    break;
  }

  free(buffer);
  return;
}
