// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-static-const_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: error-path-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация и переход по метке в случае истинности проверки.

#include <stdlib.h>

int buffer[29];

int func(unsigned int param) {
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 20) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (index >= 29) {

    index = 29 - 1;

    goto error_label;
  }

  exit(0);

error_label:
  result = buffer[index];

  return result;
}
