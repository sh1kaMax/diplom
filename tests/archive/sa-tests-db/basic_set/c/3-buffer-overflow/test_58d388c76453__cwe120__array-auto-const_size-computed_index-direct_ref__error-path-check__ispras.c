// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int func(unsigned int param) {
  int buffer[27];
  int result = 0;
  unsigned int index = 0;

  if (param > 0 && param < 21) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (index >= 27)
    goto error_label;

  exit(0);

error_label:
  result = buffer[index]; // FLAW

  return result;
}
