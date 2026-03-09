// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-dynamic-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdlib.h>
#include <string.h>

int result = 0;
void use_mem_to_keep_memset(int *);

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

void func(void) {
  int *buffer = (int *)malloc(100 * sizeof(int));
  unsigned int index = 0;
  int size = 100;

  int local_var = 21;

  index = size + 1;

  if (callee(local_var, 38) > 0) {
    exit(0);
  }

  memset(buffer, 0, index * sizeof(int)); // FLAW
  use_mem_to_keep_memset(buffer);

  free(buffer);
  return;
}
