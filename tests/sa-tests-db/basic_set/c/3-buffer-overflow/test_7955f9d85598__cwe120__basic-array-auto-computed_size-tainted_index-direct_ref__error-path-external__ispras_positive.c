// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// basic-array-auto-computed_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера вычисляется (передаётся в качестве параметра функции).
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdio.h>
#include <stdlib.h>

int external_func(void);

int func(unsigned int param) {
  int buffer[param];
  int result = 0;
  unsigned int index = 0;

  scanf("%u", &index);

  if (external_func())
    goto error_label;

  index = param - 1;

  exit(0);

error_label:
  result = buffer[index]; // FLAW

  return result;
}
