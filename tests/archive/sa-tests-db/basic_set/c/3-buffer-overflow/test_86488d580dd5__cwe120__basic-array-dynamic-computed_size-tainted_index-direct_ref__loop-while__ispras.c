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
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними

#include <stdio.h>
#include <stdlib.h>

int func(unsigned int param) {
  int *buffer = (int *)malloc(param * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  int var;

  scanf("%u", &index);

  var = 0;

  while (var < 10)
    var++;

  result = buffer[index]; // FLAW

  free(buffer);
  return result;
}
