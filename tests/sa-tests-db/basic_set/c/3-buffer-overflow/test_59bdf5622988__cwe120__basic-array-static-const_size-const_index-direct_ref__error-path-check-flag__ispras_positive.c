// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-static-const_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int result = 0;
int buffer[31];

void func(void) {
  unsigned int index = 0;

  int flag = 0;

  index = 31;

  if (index >= 31)
    flag = 1;

  if (flag != 0)
    goto error_label;

  index = 31 - 1;

  exit(0);

error_label:
  result = buffer[index]; // FLAW

  return;
}
