// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-dynamic-const_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора

#include <stdlib.h>

int func(unsigned int param) {
  int *buffer = (int *)malloc(32 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  int var;

  if (param > 0 && param < 25) {
    index = (param * 2 + 1);
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  case 1:
    result = buffer[index];
    break;
  }

  free(buffer);
  return result;
}
