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
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции

#include <stdio.h>
#include <stdlib.h>

int func(unsigned int param, int param2) {
  int *buffer = (int *)malloc(param * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  scanf("%u", &index);

  if (param2 > 42 && param2 < 53) {
    result = buffer[index]; // FLAW
  }

  free(buffer);
  return result;
}
