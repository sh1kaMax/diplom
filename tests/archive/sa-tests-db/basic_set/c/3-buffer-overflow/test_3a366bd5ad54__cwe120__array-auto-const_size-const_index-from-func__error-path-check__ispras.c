// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 6; }

void func(void) {
  int buffer[23];
  unsigned int index = 0;

  index = 23;

  if (index >= 23)
    goto error_label;

  index = 23 - 1 - 6;

  exit(0);

error_label:
  index = index_change_func(index);
  result = buffer[index]; // FLAW

  return;
}
