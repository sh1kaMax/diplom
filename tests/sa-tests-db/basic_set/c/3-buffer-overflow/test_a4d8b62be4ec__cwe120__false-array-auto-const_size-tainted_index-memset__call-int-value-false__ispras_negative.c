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
// Поточный вариант: call-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int callee(int par1) {
  if (par1 > 17)
    return 20;

  return 10;
}

void func(void) {
  int buffer[24];
  int result = 0;
  unsigned int index = 0;

  int local_var = -3;

  scanf("%u", &index);

  if (callee(local_var) == 10) {
    exit(0);
  }

  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  return;
}
