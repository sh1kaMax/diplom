// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-computed_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс вычисляется (передаётся в качестве параметра
// функции).
//
// Поточный вариант: switch-default-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора выбора

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int func(unsigned int param) {
  int buffer[34];
  int result = 0;
  unsigned int index = 0;

  int var;

  if (param > 0 && param < 26) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  var = 0;

  switch (var) {
  default:
    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
    break;
  case 0:
    exit(0);
    break;
  }

  return result;
}
