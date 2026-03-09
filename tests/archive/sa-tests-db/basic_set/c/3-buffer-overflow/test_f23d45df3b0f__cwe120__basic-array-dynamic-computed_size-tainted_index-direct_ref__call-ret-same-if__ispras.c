// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// basic-array-dynamic-computed_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера вычисляется (передаётся в качестве параметра функции).
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: call-ret-same-if.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая возвращает свой аргумент, в зависимости от другого
// параметра. Проверка в вызывающей функции неуспешна и выполнение достигает
// стока

#include <stdio.h>
#include <stdlib.h>

int callee(unsigned int par1, int par2) {
  if (par2 <= 10)
    return par1;

  return 10;
}

int func(unsigned int param) {
  int *buffer = (int *)malloc(param * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  int local_res = callee(param, 20);

  scanf("%u", &index);

  if (local_res != 10) {
    exit(0);
  }

  result = buffer[index]; // FLAW

  free(buffer);
  return result;
}
