// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-basic-array-dynamic-computed_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в динамической памяти.
// Буфер является обычным массивом.
// Размер буфера вычисляется (передаётся в качестве параметра функции).
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки, фильтрация и последующий
// переход по метке со стоком.

#include <stdlib.h>

int func(unsigned int param) {
  int *buffer = (int *)malloc(param * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  int flag = 0;

  index = 28;

  if (index >= param)
    flag = 1;

  if (flag != 0) {

    index = param - 1;

    goto error_label;
  }

  exit(0);

error_label:
  result = buffer[index];

  free(buffer);
  return result;
}
