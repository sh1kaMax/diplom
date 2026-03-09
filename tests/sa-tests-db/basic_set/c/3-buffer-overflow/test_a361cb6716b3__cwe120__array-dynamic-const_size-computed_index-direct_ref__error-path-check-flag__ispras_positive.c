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
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int func(unsigned int param) {
  int *buffer = (int *)malloc(29 * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  int flag = 0;

  if (param > 0 && param < 24) {
    index = (param * 2 + 1);
  }

  if (index >= 29)
    flag = 1;

  if (flag != 0)
    goto error_label;

  exit(0);

error_label:
  result = buffer[index]; // FLAW

  free(buffer);
  return result;
}
