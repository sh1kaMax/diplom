// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-computed_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера вычисляется (передаётся в качестве параметра функции).
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int func(unsigned int param) {
  int buffer[param];
  int result = 0;
  unsigned int index = 0;

  int flag = 0;

  index = param * 2;

  if (index >= param)
    flag = 1;

  if (flag != 0)
    goto error_label;

  exit(0);

error_label:
  result = buffer[index]; // FLAW

  return result;
}
