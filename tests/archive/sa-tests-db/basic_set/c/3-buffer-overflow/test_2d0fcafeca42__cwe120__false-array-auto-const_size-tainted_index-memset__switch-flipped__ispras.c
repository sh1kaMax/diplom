// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-auto-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: switch-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

void func(void) {
  int buffer[33];
  int result = 0;
  unsigned int index = 0;

  int var;

  scanf("%u", &index);

  var = 0;

  switch (var) {
  case 1:
    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
    break;
  case 0:
    exit(0);
    break;
  }

  return;
}
