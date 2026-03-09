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
// Поточный вариант: error-path-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация и переход по метке в случае истинности проверки.

#include <stdlib.h>

int func(unsigned int param) {
  int *buffer = (int *)malloc(param * sizeof(int));
  int result = 0;
  unsigned int index = 0;

  index = 26;

  if (index >= param) {

    index = param - 1;

    goto error_label;
  }

  exit(0);

error_label:
  result = buffer[index];

  free(buffer);
  return result;
}
