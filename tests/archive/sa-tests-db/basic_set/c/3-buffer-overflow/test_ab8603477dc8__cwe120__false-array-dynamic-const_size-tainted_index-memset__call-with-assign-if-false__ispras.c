// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-dynamic-const_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 148;
}

void func(void) {
  int *buffer = (int *)malloc(33 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  int var = 0;

  scanf("%u", &index);

  callee(&var, 8);

  if (var > 85) {
    exit(0);
  }

  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  free(buffer);
  return;
}
