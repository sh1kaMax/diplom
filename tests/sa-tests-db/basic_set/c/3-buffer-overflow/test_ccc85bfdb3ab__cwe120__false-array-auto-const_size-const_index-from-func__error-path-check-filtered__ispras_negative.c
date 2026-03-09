// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 7; }

void func(void) {
  int buffer[39];
  unsigned int index = 0;

  index = 39;

  if (index >= 39) {

    index = 39 - 1 - 7;

    goto error_label;
  }

  exit(0);

error_label:
  index = index_change_func(index);
  result = buffer[index];

  return;
}
