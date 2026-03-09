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
// Поточный вариант: call-ret-same-if.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая возвращает свой аргумент, в зависимости от другого
// параметра. Проверка в вызывающей функции успешна и выполнение не достигает
// стока

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int callee(unsigned int par1, int par2) {
  if (par2 <= 10)
    return par1;

  return 10;
}

int func(unsigned int param) {
  int buffer[33];
  int result = 0;
  unsigned int index = 0;

  int local_res = callee(param, 20);

  if (param > 0 && param < 28) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (local_res == 10) {
    exit(0);
  }

  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  return result;
}
